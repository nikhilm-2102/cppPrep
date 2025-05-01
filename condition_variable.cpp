#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;

void waitForData() {
    std::unique_lock<std::mutex> lock(mtx);
    // Wait until dataReady becomes true
    while (!dataReady) {
        cv.wait(lock);  // No lambda used here
    }
    std::cout << "Data is ready! Processing it..." << std::endl;
}

void setDataReady() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    {
        std::lock_guard<std::mutex> lock(mtx);
        dataReady = true;
    }
    cv.notify_one();
}

int main() {
    std::thread consumer(waitForData);
    std::thread producer(setDataReady);

    consumer.join();
    producer.join();

    return 0;
}
