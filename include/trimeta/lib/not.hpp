//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_NOT_HPP
#define TRIMETA_NOT_HPP

#include <dimeta/macro/macro.hpp>
#include <trimeta/unit_primitives.hpp>

namespace tm::lib {
    namespace dmm = dm::macro;

    template <
            class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using not_8_8 = dmm::assembly<
            dmm::in<A0, A1, A2, A3, A4, A5, A6, A7>,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
            unit_not<A0*, O0*>,
            unit_not<A1*, O1*>,
            unit_not<A2*, O2*>,
            unit_not<A3*, O3*>,
            unit_not<A4*, O4*>,
            unit_not<A5*, O5*>,
            unit_not<A6*, O6*>,
            unit_not<A7*, O7*>
    >;
}

#endif //TRIMETA_NOT_HPP
