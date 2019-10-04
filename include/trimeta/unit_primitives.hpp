//
// Created by Mark on 9/19/2019.
//

#ifndef TRIMETA_UNIT_PRIMITIVES_HPP
#define TRIMETA_UNIT_PRIMITIVES_HPP

#include <dimeta/primitives.hpp>

#include <dimeta/macro/primitives.hpp>
#include <dimeta/macro/delay.hpp>

#include <trimeta/detail/generic_primitives.hpp>

namespace tm {
    namespace detail {
        template <class...>
        using unit_delay = dm::macro::fixed_delay<dm::time_constant<1>, dm::time_constant<1>>;

        template <class A, class B>
        using unit_delay_2 = unit_delay<A, B>;

        template <class A>
        using unit_delay_1 = unit_delay<A>;
    }

    template <class A, class B, class O>
    using unit_and2 = tm::detail::generic_and2<A, B, O, detail::unit_delay_2>;

    template <class A, class B, class O>
    using unit_nand2 = tm::detail::generic_nand2<A, B, O, detail::unit_delay_2>;

    template <class A, class B, class O>
    using unit_or2 = tm::detail::generic_or2<A, B, O, detail::unit_delay_2>;

    template <class A, class B, class O>
    using unit_nor2 = tm::detail::generic_nor2<A, B, O, detail::unit_delay_2>;

    template <class A, class O>
    using unit_not = tm::detail::generic_not<A, O, detail::unit_delay_1>;

    template <class A, class O>
    using unit_buf = tm::detail::generic_buf<A, O, detail::unit_delay_1>;

    template <class A, class B, class O>
    using unit_xor2 = tm::detail::generic_xor2<A, B, O, detail::unit_delay_2>;
}

#endif //TRIMETA_UNIT_PRIMITIVES_HPP
