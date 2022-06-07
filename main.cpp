#include "interface_based_model.hpp"
#include "template_based_model.hpp"

int main()
{
    {
        using namespace interface_based_model;
        auto engine = std::make_unique<diesel_engine>();
        car test_car(std::move(engine));
        test_car.start();
    }

    {
        using namespace template_based_model;
        electric_engine engine {};
        car test_car(std::move(engine));
        test_car.start();
    }

    return 0;
}
