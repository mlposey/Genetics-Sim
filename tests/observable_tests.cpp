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

    // 'other' should still remain
    ASSERT_EQ(1, observable.getObserverCount());
    ASSERT_TRUE(observable.contains(other));

    ASSERT_FALSE(observable.contains(observer));
}

// TODO: Create test for Observable::contains
