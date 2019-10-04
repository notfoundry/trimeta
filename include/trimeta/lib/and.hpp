//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_AND_HPP
#define TRIMETA_AND_HPP

#include <dimeta/macro/macro.hpp>
#include <trimeta/unit_primitives.hpp>

namespace tm::lib {
    namespace dmm = dm::macro;

    template <
            class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7,
            class B0, class B1, class B2, class B3, class B4, class B5, class B6, class B7,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using and_8_8 = dmm::assembly<
            dmm::in<A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, B2, B3, B4, B5, B6, B7>,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
            unit_and2<A0*, B0*, O0*>,
            unit_and2<A1*, B1*, O1*>,
            unit_and2<A2*, B2*, O2*>,
            unit_and2<A3*, B3*, O3*>,
            unit_and2<A4*, B4*, O4*>,
            unit_and2<A5*, B5*, O5*>,
            unit_and2<A6*, B6*, O6*>,
            unit_and2<A7*, B7*, O7*>
    >;
}

#endif //TRIMETA_AND_HPP
