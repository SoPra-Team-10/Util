/**
 * @file Timer.h
 * @author paul, tim, björn
 * @date 01.05.19
 * @brief Declaration of the Timer class
 */

#ifndef SERVER_TIMER_H
#define SERVER_TIMER_H


#include <thread>
#include <future>
#include <atomic>
#include <variant>

namespace util {
    /**
     * The timer class represents a simple single-shot timer with an interface
     * similar to the `setTimeout()` function in javascript. Additionally it
     * supports pausing and resuming the timeout.
     */
    class Timer {
    public:
        /**
         * Not copyable
         */
        Timer(const Timer &timer) = delete;

        /**
         * Not cpy assignable
         */
        Timer& operator=(const Timer &timer) = delete;

        /**
         * Not movable
         */
        Timer(Timer&& timer) = delete;

        /**
         * Not move assignable
         */
        Timer& operator=(Timer &&timer) = delete;

        /**
         *
         * @param delay after the delay, the code will be execute
         */
        template<typename Function>
        void setTimeout(Function function, int delay);

        /**
         * Pauses the Timer
         */
        void pause();

        /**
         * Resumes the timer
         */
        void resume();

        /**
         * Stops the timer without calling the event
         */
        void stop();

        /**
         * DTor: Necessary for cleanup and stopping of the thread
         */
        ~Timer();

        using Timepoint = std::chrono::time_point<std::chrono::system_clock>;
        using Duration = std::chrono::milliseconds;
    private:
        std::atomic_bool stopRequired{false};
        std::condition_variable conditionVariable;
        std::future<void> threadHandler;
        std::thread functionThreadHandler;
        std::mutex mutex;
        std::mutex timeLock;
        std::variant<Timepoint, Duration> time;
    };

    template<typename Function>
    void Timer::setTimeout(Function function, int delay) {
        stopRequired = false;
        time = std::chrono::system_clock::now() + std::chrono::milliseconds{delay};
        if (threadHandler.valid()) {
            throw std::runtime_error("Timer not finished, call stop() first");
        }

        threadHandler = std::async(std::launch::async, [this, &function](){
            std::unique_lock<std::mutex> lock{mutex};
            while (!stopRequired) {
                timeLock.lock();
                if (std::holds_alternative<Timepoint>(time)) { // Running
                    auto now = std::chrono::system_clock::now();
                    auto timepoint = std::get<Timepoint>(time);
                    timeLock.unlock();
                    if (now >= timepoint) {
                        functionThreadHandler = std::thread(function);
                        functionThreadHandler.detach();
                        return;
                    }
                    conditionVariable.wait_until(lock, timepoint, [&timepoint, this](){
                        return timepoint > std::chrono::system_clock::now() || stopRequired;
                    });
                } else { // Pause
                    timeLock.unlock();
                    conditionVariable.wait(lock, [this](){ return static_cast<bool>(stopRequired);});
                }
            }
        });
    }
}

#endif //SERVER_TIMER_H
