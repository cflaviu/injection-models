#pragma once
#include <iostream>
#include <memory>

namespace interface_based_model
{
    class engine_interface
    {
    public:
        using unique_ptr = std::unique_ptr<engine_interface>;

        virtual ~engine_interface() = default;

        virtual void start() = 0;
        virtual void stop() = 0;
    };

    class diesel_engine: public engine_interface
    {
    public:
        diesel_engine() { std::cout << "diesel_engine default ctor\n"; }
        diesel_engine(const diesel_engine&) { std::cout << "diesel_engine copy ctor\n"; }
        diesel_engine(diesel_engine&&) { std::cout << "diesel_engine move ctor\n"; }

        void start() override {}
        void stop() override {}
    };

    class car
    {
    public:
        car(engine_interface::unique_ptr engine): _engine(std::move(engine)) {}

        const engine_interface& engine() const noexcept { return *_engine.get(); }
        engine_interface& engine() noexcept { return *_engine.get(); }

        void start() { _engine->start(); }
        void stop() { _engine->stop(); }

    private:
        engine_interface::unique_ptr _engine;
    };
}
