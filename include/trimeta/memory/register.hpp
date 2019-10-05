//
// Created by Mark on 10/4/2019.
//

#ifndef TRIMETA_REGISTER_HPP
#define TRIMETA_REGISTER_HPP

#include <dimeta/macro/macro.hpp>

#include <trimeta/unit_primitives.hpp>

#include <trimeta/lib/mux.hpp>
#include <trimeta/memory/dff.hpp>

namespace tm::mem {
    namespace dmm = dm::macro;

    template <class Clock, class Load, class Data, class Out>
    using register_1bit = dmm::assembly<
            dmm::in<Clock, Load, Data>,
            dmm::out<Out>,

            lib::mux_2_1<Data*, Out*, Load*, dmm::wire<0>>,
            posedge_ms_d_flipflop<Clock*, dmm::wire<0>, Out*, dmm::wire<'~', 'O', 'u', 't'>>
    >;

    template <
            class C, class L,
            class D0, class D1,
            class O0, class O1
    >
    using register_2bit = dmm::assembly<
            dmm::in<C, L, D0, D1>,
            dmm::out<O0, O1>,
            register_1bit<C*, L*, D0*, O0*>,
            register_1bit<C*, L*, D1*, O1*>
    >;

    template <
            class C, class L,
            class D0, class D1, class D2, class D3,
            class O0, class O1, class O2, class O3
    >
    using register_4bit = dmm::assembly<
            dmm::in<C, L, D0, D1, D2, D3>,
            dmm::out<O0, O1, O2, O3>,
            register_2bit<C*, L*, D0*, D1*, O0*, O1*>,
            register_2bit<C*, L*, D2*, D3*, O2*, O3*>
    >;

    template <
            class C, class L,
            class D0, class D1, class D2, class D3, class D4, class D5, class D6, class D7,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using register_8bit = dmm::assembly<
            dmm::in<C, L, D0, D1, D2, D3, D4, D5, D6, D7>,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
            register_4bit<C*, L*, D0*, D1*, D2*, D3*, O0*, O1*, O2*, O3*>,
            register_4bit<C*, L*, D4*, D5*, D6*, D7*, O4*, O5*, O6*, O7*>
    >;
}

#endif //TRIMETA_REGISTER_HPP
