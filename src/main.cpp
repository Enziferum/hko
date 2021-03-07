#include "hko/App.h"
#include "hko/States.h"
#include "hko/StrategyState.h"
#include "hko/MenuState.h"

int main() {
    hko::App app;
    hko::Configuration configuration = hko::Configuration::create();


    hko::MenuState::Ptr menu_state =
            std::make_shared<hko::MenuState>(app, configuration);

    hko::StrategyState::Ptr strategy_state
        = std::make_shared<hko::StrategyState>(app, configuration);

    app.register_state(hko::States::Menu, menu_state);
    app.register_state(hko::States::Strategy, strategy_state);
    app.run();

    return 0;
}
