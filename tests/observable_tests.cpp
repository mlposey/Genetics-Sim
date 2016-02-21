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
    MockObserver observer;
    Observable<int> observable;
};


/**
 * This test assumes the following behavior:
 * 1.) Observable::contains returns true if it contains the provided argument
 * 2.) Observable::contains false if it does not contain the provided argument
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ObservableTests, contains) {
    observable.addObserver(observer);
    ASSERT_TRUE(observable.contains(observer));

    MockObserver o;
    ASSERT_FALSE(observable.contains(o));
}

/**
 * This test expects the following behavior:
 * 1.) Observable::addObserver stores the address of the provided argument
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ObservableTests, addObserver) {
    // The Observable object should start off empty
    ASSERT_EQ(0, observable.getObserverCount());

    observable.addObserver(observer);

    ASSERT_EQ(1, observable.getObserverCount());
    ASSERT_TRUE(observable.contains(observer));

    observable.addObserver(observer);

    ASSERT_EQ(2, observable.getObserverCount());
}

/**
 * This test expects the following behavior:
 * 1.) Observable::removeObserver removes the supplied argument and all copies
 * 2.) Observable::removeObserver DOES NOT remove observers that were not
 *     specified
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ObservableTests, removeObserver) {
    ASSERT_EQ(0, observable.getObserverCount());

    observable.addObserver(observer);
    observable.addObserver(observer);

    MockObserver other;
    observable.addObserver(other);

    ASSERT_EQ(3, observable.getObserverCount());

    observable.removeObserver(observer);
    // TODO: Remove nonexistant observer

    // 'other' should still remain
    ASSERT_EQ(1, observable.getObserverCount());
    ASSERT_TRUE(observable.contains(other));

    ASSERT_FALSE(observable.contains(observer));
}

/**
 * This test expects the following behavior:
 * 1.) Observable::notifyAll calls the notify method of all of its observers
 *
 * Deviation from the above should result in a failed test.
 */
TEST_F(ObservableTests, notifyAll) {
    observable.notifyAll(0);

    observable.addObserver(observer);
    observable.notifyAll(0);

    ASSERT_TRUE(observer.isMockNotified);
}
