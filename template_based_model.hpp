#pragma once
#include <iostream>

namespace template_based_model
{
    class electric_engine
    {
    public:
        electric_engine() { std::cout << "electric_engine default ctor\n"; }
        electric_engine(const electric_engine&) { std::cout << "electric_engine copy ctor\n"; }
        electric_engine(electric_engine&&) { std::cout << "electric_engine move ctor\n"; }

        void start() {}
        void stop() {}
    };

    template <typename _Engine>
    class car
    {
    public:
        using engine_type = _Engine;

        car(engine_type engine): _engine(std::move(engine)) {}

        const engine_type& engine() const noexcept { return _engine; }
        engine_type& engine() noexcept { return _engine; }

        void start() { _engine.start(); }
        void stop() { _engine.stop(); }

    private:
        engine_type _engine;
    };
}
