#pragma once

#include "Types.h"
#include "Containers/Array.h"

class FComm
{
public:
    explicit FComm();

    FComm &operator=(FComm const &) & = delete;
    FComm &operator=(FComm &&) & = delete;
    FComm(FComm const &) = delete;
    FComm(FComm &&) = delete;
    virtual ~FComm() = default;

    void Subscribe(SubscriptionFunction Callback);

private:
    TArray<SubscriptionFunction> Subscriptions;
};
