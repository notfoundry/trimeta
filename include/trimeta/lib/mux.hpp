//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_MUX_HPP
#define TRIMETA_MUX_HPP

#include <dimeta/macro/macro.hpp>
#include <trimeta/unit_primitives.hpp>

#include <trimeta/lib/or.hpp>
#include <trimeta/lib/decoder.hpp>

namespace tm::lib {
    namespace dmm = dm::macro;

    template <
            class I0, class I1,
            class S0,
            class O
    >
    using mux_2_1 = dmm::assembly<
            dmm::in<I0, I1, S0>,
            dmm::out<O>,

            unit_not<S0*, dmm::wire<0>>,
            unit_and2<I0*, dmm::wire<0>, dmm::wire<1>>,
            unit_and2<I1*, S0*, dmm::wire<2>>,
            unit_or2<dmm::wire<1>, dmm::wire<2>, O*>
    >;

    template <
            class I0, class I1, class I2, class I3,
            class S0, class S1,
            class O
    >
    using mux_4_1 = dmm::assembly<
            dmm::in<I0, I1, I2, I3, S0, S1>,
            dmm::out<O>,

            decoder_2_4<S0*, S1*, dmm::wire<'D', 0>, dmm::wire<'D', 1>, dmm::wire<'D', 2>, dmm::wire<'D', 3>>,
            unit_and2<I0*, dmm::wire<'D', 0>, dmm::wire<'O', 0>>,
            unit_and2<I1*, dmm::wire<'D', 1>, dmm::wire<'O', 1>>,
            unit_and2<I2*, dmm::wire<'D', 2>, dmm::wire<'O', 2>>,
            unit_and2<I3*, dmm::wire<'D', 3>, dmm::wire<'O', 3>>,
            or_4_1<dmm::wire<'O', 0>, dmm::wire<'O', 1>, dmm::wire<'O', 2>, dmm::wire<'O', 3>, O*>
    >;

    template <
            class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7,
            class S0, class S1, class S2,
            class O
    >
    using mux_8_1 = dmm::assembly<
            dmm::in<I0, I1, I2, I3, I4, I5, I6, I7, S0, S1, S2>,
            dmm::out<O>,

            mux_4_1<I0*, I1*, I2*, I3*, S0*, S1*, dmm::wire<0>>,
            mux_4_1<I4*, I5*, I6*, I7*, S0*, S1*, dmm::wire<1>>,
            mux_2_1<dmm::wire<0>, dmm::wire<1>, S2*, O*>
    >;

    template <
            class I0_0, class I0_1, class I0_2, class I0_3, class I0_4, class I0_5, class I0_6, class I0_7,
            class I1_0, class I1_1, class I1_2, class I1_3, class I1_4, class I1_5, class I1_6, class I1_7,
            class S0,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using mux_8_2_1 = dmm::assembly<
            dmm::in<
                    I0_0, I0_1, I0_2, I0_3, I0_4, I0_5, I0_6, I0_7,
                    I1_0, I1_1, I1_2, I1_3, I1_4, I1_5, I1_6, I1_7,
                    S0
            >,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
            mux_2_1<I0_0*, I1_0*, S0*, O0*>,
            mux_2_1<I0_1*, I1_1*, S0*, O1*>,
            mux_2_1<I0_2*, I1_2*, S0*, O2*>,
            mux_2_1<I0_3*, I1_3*, S0*, O3*>,
            mux_2_1<I0_4*, I1_4*, S0*, O4*>,
            mux_2_1<I0_5*, I1_5*, S0*, O5*>,
            mux_2_1<I0_6*, I1_6*, S0*, O6*>,
            mux_2_1<I0_7*, I1_7*, S0*, O7*>
    >;

    template <
            class I0_0, class I0_1, class I0_2, class I0_3, class I0_4, class I0_5, class I0_6, class I0_7,
            class I1_0, class I1_1, class I1_2, class I1_3, class I1_4, class I1_5, class I1_6, class I1_7,
            class I2_0, class I2_1, class I2_2, class I2_3, class I2_4, class I2_5, class I2_6, class I2_7,
            class I3_0, class I3_1, class I3_2, class I3_3, class I3_4, class I3_5, class I3_6, class I3_7,
            class S0, class S1,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using mux_8_4_1 = dmm::assembly<
            dmm::in<
                    I0_0, I0_1, I0_2, I0_3, I0_4, I0_5, I0_6, I0_7,
                    I1_0, I1_1, I1_2, I1_3, I1_4, I1_5, I1_6, I1_7,
                    I2_0, I2_1, I2_2, I2_3, I2_4, I2_5, I2_6, I2_7,
                    I3_0, I3_1, I3_2, I3_3, I3_4, I3_5, I3_6, I3_7,
                    S0, S1
            >,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
            mux_4_1<I0_0*, I1_0*, I2_0*, I3_0*, S0*, S1*, O0*>,
            mux_4_1<I0_1*, I1_1*, I2_1*, I3_1*, S0*, S1*, O1*>,
            mux_4_1<I0_2*, I1_2*, I2_2*, I3_2*, S0*, S1*, O2*>,
            mux_4_1<I0_3*, I1_3*, I2_3*, I3_3*, S0*, S1*, O3*>,
            mux_4_1<I0_4*, I1_4*, I2_4*, I3_4*, S0*, S1*, O4*>,
            mux_4_1<I0_5*, I1_5*, I2_5*, I3_5*, S0*, S1*, O5*>,
            mux_4_1<I0_6*, I1_6*, I2_6*, I3_6*, S0*, S1*, O6*>,
            mux_4_1<I0_7*, I1_7*, I2_7*, I3_7*, S0*, S1*, O7*>
    >;
}

#endif //TRIMETA_MUX_HPP
