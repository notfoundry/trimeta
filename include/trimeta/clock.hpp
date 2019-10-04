//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_CLOCK_HPP
#define TRIMETA_CLOCK_HPP

#include <dimeta/primitives.hpp>

#include <dimeta/macro/primitives.hpp>
#include <dimeta/macro/delay.hpp>

#include <trimeta/detail/generic_primitives.hpp>
#include <trimeta/unit_primitives.hpp>

namespace tm {
    namespace detail {
        template <dm::virtual_time Period>
        struct clock_delay {
            template <class>
            using f = dm::macro::fixed_delay<dm::time_constant<Period>, dm::time_constant<Period>>;
        };
    }

    template <class I, class O, dm::virtual_time Period>
    using ring_oscillator = dm::macro::assembly<
            dm::macro::in<I>,
            dm::macro::out<O>,
            tm::detail::generic_not<I*, I*, detail::clock_delay<Period>::template f>,
            unit_buf<I*, O*>
    >;
}

#endif //TRIMETA_CLOCK_HPP
