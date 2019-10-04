//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_GENERIC_PRIMITIVES_HPP
#define TRIMETA_GENERIC_PRIMITIVES_HPP

#include <dimeta/primitives.hpp>

#include <dimeta/macro/primitives.hpp>
#include <dimeta/macro/delay.hpp>

#include <dimeta/function/and_function.hpp>
#include <dimeta/function/nand_function.hpp>
#include <dimeta/function/or_function.hpp>
#include <dimeta/function/nor_function.hpp>
#include <dimeta/function/buffer_function.hpp>
#include <dimeta/function/not_function.hpp>
#include <dimeta/function/xor_function.hpp>

namespace tm::detail {
    template <class A, class B, class O, template <class, class> class Delay>
    using generic_and2 = dm::macro::cell<
            dm::macro::in<A, B>,
            dm::macro::out<O>,
            dm::function::and_function,
            Delay<A, B>
    >;

    template <class A, class B, class O, template <class, class> class Delay>
    using generic_nand2 = dm::macro::cell<
            dm::macro::in<A, B>,
            dm::macro::out<O>,
            dm::function::nand_function,
            Delay<A, B>
    >;

    template <class A, class B, class O, template <class, class> class Delay>
    using generic_or2 = dm::macro::cell<
            dm::macro::in<A, B>,
            dm::macro::out<O>,
            dm::function::or_function,
            Delay<A, B>
    >;

    template <class A, class B, class O, template <class, class> class Delay>
    using generic_nor2 = dm::macro::cell<
            dm::macro::in<A, B>,
            dm::macro::out<O>,
            dm::function::nor_function,
            Delay<A, B>
    >;

    template <class A, class O, template <class> class Delay>
    using generic_not = dm::macro::cell<
            dm::macro::in<A>,
            dm::macro::out<O>,
            dm::function::not_function,
            Delay<A>
    >;

    template <class A, class O, template <class> class Delay>
    using generic_buf = dm::macro::cell<
            dm::macro::in<A>,
            dm::macro::out<O>,
            dm::function::buffer_function,
            Delay<A>
    >;

    template <class A, class B, class O, template <class, class> class Delay>
    using generic_xor2 = dm::macro::cell<
            dm::macro::in<A, B>,
            dm::macro::out<O>,
            dm::function::xor_function,
            Delay<A, B>
    >;
}

#endif //TRIMETA_GENERIC_PRIMITIVES_HPP
