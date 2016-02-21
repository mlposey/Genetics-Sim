#include <gtest/gtest.h>

#include "../Genetics/Observable.h"

// IObserver is an ADT.
// We need to define a mock class for testing Observable
class MockObserver : public IObserver<int> {
public:
    bool isMockNotified;

    MockObserver() : isMockNotified(false) {}

    void notify(const int &i) override {
        isMockNotified = true;
    }
};

class ObservableTests : public testing::Test {
public:
    MockObserver *observer;
    Observable<int> observable;

    ObservableTests()
        : observer(new MockObserver())
    {}

    ~ObservableTests() {
        delete observer;
    }
};

/**
 * This test expects the following behavior:
 * 1.) Observable::addObserver stores the address of the provided argument
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ObservableTests, addObserver) {
    // The Observable object should start off empty
    ASSERT_EQ(0, observable.getObserverCount());

    observable.addObserver(*observer);

    ASSERT_EQ(1, observable.getObserverCount());


}
