class H2O {
private: 
    int d; 
    std::mutex mtx;
    std::condition_variable cv;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lck(mtx);
        while (d>=2) {
            cv.wait(lck);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        d++;
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lck(mtx);
        while (d<0) {
            cv.wait(lck);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        d-=2;
        cv.notify_one();
    }
};