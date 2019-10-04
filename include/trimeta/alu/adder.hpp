//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_ADDER_HPP
#define TRIMETA_ADDER_HPP

#include <dimeta/macro/macro.hpp>
#include <trimeta/unit_primitives.hpp>

namespace tm::alu {
    namespace dmm = dm::macro;

    template <class A, class B, class S, class C>
    using half_adder = dmm::assembly<
            dmm::in<A, B>,
            dmm::out<S, C>,

            unit_xor2<A*, B*, S*>,
            unit_and2<A*, B*, C*>
    >;

    template <class A, class B, class CIn, class S, class COut>
    using full_adder = dmm::assembly<
            dmm::in<A, B, CIn>,
            dmm::out<S, COut>,

            half_adder<A*, B*, dmm::wire<0>, dmm::wire<1>>,
            half_adder<dmm::wire<0>, CIn*, S*, dmm::wire<2>>,
            unit_or2<dmm::wire<1>, dmm::wire<2>, COut*>
    >;

    template <
            class CIn,
            class A0, class A1,
            class B0, class B1,
            class S0, class S1,
            class COut
    >
    using rc_adder_2 = dmm::assembly<
            dmm::in<CIn, A0, A1, B0, B1>,
            dmm::out<S0, S1, COut>,

            full_adder<A0*, B0*, CIn*, S0*, dmm::wire<0>>,
            full_adder<A1*, B1*, dmm::wire<0>, S1*, COut*>
    >;

    template <
            class CIn,
            class A0, class A1, class A2, class A3,
            class B0, class B1, class B2, class B3,
            class S0, class S1, class S2, class S3,
            class COut
    >
    using rc_adder_4 = dmm::assembly<
            dmm::in<CIn, A0, A1, A2, A3, B0, B1, B2, B3>,
            dmm::out<S0, S1, S2, S3, COut>,
            rc_adder_2<CIn*, A0*, A1*, B0*, B1*, S0*, S1*, dmm::wire<0>>,
            rc_adder_2<dmm::wire<0>, A2*, A3*, B2*, B3*, S2*, S3*, COut*>
    >;

    template <
            class CIn,
            class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7,
            class B0, class B1, class B2, class B3, class B4, class B5, class B6, class B7,
            class S0, class S1, class S2, class S3, class S4, class S5, class S6, class S7,
            class COut
    >
    using rc_adder_8 = dmm::assembly<
            dmm::in<CIn, A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, B2, B3, B4, B5, B6, B7>,
            dmm::out<S0, S1, S2, S3, S4, S5, S6, S7, COut>,
            rc_adder_4<CIn*, A0*, A1*, A2*, A3*, B0*, B1*, B2*, B3*, S0*, S1*, S2*, S3*, dmm::wire<0>>,
            rc_adder_4<dmm::wire<0>, A4*, A5*, A6*, A7*, B4*, B5*, B6*, B7*, S4*, S5*, S6*, S7*, COut*>
    >;
}

#endif //TRIMETA_ADDER_HPP
