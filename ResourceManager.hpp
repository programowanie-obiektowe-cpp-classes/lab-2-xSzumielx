#pragma once

#include "Resource.hpp"
struct ResourceManager
{
public:
    ResourceManager() : resource_(new Resource()) {}
    ~ResourceManager() { delete resource_; }
    ResourceManager(const ResourceManager& other) : resource_(new Resource(*other.resource_)) {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            Resource* fresh = new Resource(*other.resource_);
            delete resource_;
            resource_ = fresh;
        }
        return *this;
    }

    double get() const { return resource_->get(); }

private:
    Resource* resource_;
};