//
// Created by Mark on 9/26/2019.
//

#ifndef TRIMETA_ALU_HPP
#define TRIMETA_ALU_HPP

#include <dimeta/macro/macro.hpp>

#include <trimeta/unit_primitives.hpp>

#include <trimeta/alu/adder.hpp>

#include <trimeta/lib/and.hpp>
#include <trimeta/lib/or.hpp>
#include <trimeta/lib/mux.hpp>

namespace tm::alu {
    namespace dmm = dm::macro;

    template <
            class Z, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using zero_or_passthrough = dmm::assembly<
            dmm::in<Z, A0, A1, A2, A3, A4, A5, A6, A7>,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
    
            unit_not<Z*, dmm::wire<'Z', '~'>>,
            unit_and2<A0*, dmm::wire<'Z', '~'>, O0*>,
            unit_and2<A1*, dmm::wire<'Z', '~'>, O1*>,
            unit_and2<A2*, dmm::wire<'Z', '~'>, O2*>,
            unit_and2<A3*, dmm::wire<'Z', '~'>, O3*>,
            unit_and2<A4*, dmm::wire<'Z', '~'>, O4*>,
            unit_and2<A5*, dmm::wire<'Z', '~'>, O5*>,
            unit_and2<A6*, dmm::wire<'Z', '~'>, O6*>,
            unit_and2<A7*, dmm::wire<'Z', '~'>, O7*>
    >;
    
    template <
            class N, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7,
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7
    >
    using negate_or_passthrough = dmm::assembly<
            dmm::in<N, A0, A1, A2, A3, A4, A5, A6, A7>,
            dmm::out<O0, O1, O2, O3, O4, O5, O6, O7>,
    
            unit_xor2<A0*, N*, O0*>,
            unit_xor2<A1*, N*, O1*>,
            unit_xor2<A2*, N*, O2*>,
            unit_xor2<A3*, N*, O3*>,
            unit_xor2<A4*, N*, O4*>,
            unit_xor2<A5*, N*, O5*>,
            unit_xor2<A6*, N*, O6*>,
            unit_xor2<A7*, N*, O7*>
    >;
    
    template <
            class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7,
            class Y0, class Y1, class Y2, class Y3, class Y4, class Y5, class Y6, class Y7,
            class ZX, class NX, class ZY, class NY, class F, class NO,
    
            class O0, class O1, class O2, class O3, class O4, class O5, class O6, class O7,
            class ZR, class NG, class OF
    >
    using alu_8 = dmm::assembly<
            dmm::in<
                    X0, X1, X2, X3, X4, X5, X6, X7,
                    Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7,
                    ZX, NX, ZY, NY, F, NO
            >,
            dmm::out<
                    O0, O1, O2, O3, O4, O5, O6, O7,
                    ZR, NG, OF
            >,
    
            zero_or_passthrough<ZX*,
                    X0*, X1*, X2*, X3*, X4*, X5*, X6*, X7*,
                    dmm::wire<'X',0,'Z'>, dmm::wire<'X',1,'Z'>, dmm::wire<'X',2,'Z'>, dmm::wire<'X',3,'Z'>,
                    dmm::wire<'X',4,'Z'>, dmm::wire<'X',5,'Z'>, dmm::wire<'X',6,'Z'>, dmm::wire<'X',7,'Z'>
            >,
            zero_or_passthrough<ZY*,
                    Y0*, Y1*, Y2*, Y3*, Y4*, Y5*, Y6*, Y7*,
                    dmm::wire<'Y',0,'Z'>, dmm::wire<'Y',1,'Z'>, dmm::wire<'Y',2,'Z'>, dmm::wire<'Y',3,'Z'>,
                    dmm::wire<'Y',4,'Z'>, dmm::wire<'Y',5,'Z'>, dmm::wire<'Y',6,'Z'>, dmm::wire<'Y',7,'Z'>
            >,
    
            negate_or_passthrough<NX*,
                    dmm::wire<'X',0,'Z'>, dmm::wire<'X',1,'Z'>, dmm::wire<'X',2,'Z'>, dmm::wire<'X',3,'Z'>,
                    dmm::wire<'X',4,'Z'>, dmm::wire<'X',5,'Z'>, dmm::wire<'X',6,'Z'>, dmm::wire<'X',7,'Z'>,
    
                    dmm::wire<'X',0,'~'>, dmm::wire<'X',1,'~'>, dmm::wire<'X',2,'~'>, dmm::wire<'X',3,'~'>,
                    dmm::wire<'X',4,'~'>, dmm::wire<'X',5,'~'>, dmm::wire<'X',6,'~'>, dmm::wire<'X',7,'~'>
            >,
            negate_or_passthrough<NY*,
                    dmm::wire<'Y',0,'Z'>, dmm::wire<'Y',1,'Z'>, dmm::wire<'Y',2,'Z'>, dmm::wire<'Y',3,'Z'>,
                    dmm::wire<'Y',4,'Z'>, dmm::wire<'Y',5,'Z'>, dmm::wire<'Y',6,'Z'>, dmm::wire<'Y',7,'Z'>,
    
                    dmm::wire<'Y',0,'~'>, dmm::wire<'Y',1,'~'>, dmm::wire<'Y',2,'~'>, dmm::wire<'Y',3,'~'>,
                    dmm::wire<'Y',4,'~'>, dmm::wire<'Y',5,'~'>, dmm::wire<'Y',6,'~'>, dmm::wire<'Y',7,'~'>
            >,
    
            unit_not<F*, dmm::wire<'F', '~'>>,
            rc_adder_8<
                    dmm::wire<'F', '~'>,
                    dmm::wire<'X',0,'~'>, dmm::wire<'X',1,'~'>, dmm::wire<'X',2,'~'>, dmm::wire<'X',3,'~'>,
                    dmm::wire<'X',4,'~'>, dmm::wire<'X',5,'~'>, dmm::wire<'X',6,'~'>, dmm::wire<'X',7,'~'>,
    
                    dmm::wire<'Y',0,'~'>, dmm::wire<'Y',1,'~'>, dmm::wire<'Y',2,'~'>, dmm::wire<'Y',3,'~'>,
                    dmm::wire<'Y',4,'~'>, dmm::wire<'Y',5,'~'>, dmm::wire<'Y',6,'~'>, dmm::wire<'Y',7,'~'>,
    
                    dmm::wire<'O',0,'+'>, dmm::wire<'O',1,'+'>, dmm::wire<'O',2,'+'>, dmm::wire<'O',3,'+'>,
                    dmm::wire<'O',4,'+'>, dmm::wire<'O',5,'+'>, dmm::wire<'O',6,'+'>, dmm::wire<'O',7,'+'>,
                    OF*
            >,
            lib::and_8_8<
                    dmm::wire<'X',0,'~'>, dmm::wire<'X',1,'~'>, dmm::wire<'X',2,'~'>, dmm::wire<'X',3,'~'>,
                    dmm::wire<'X',4,'~'>, dmm::wire<'X',5,'~'>, dmm::wire<'X',6,'~'>, dmm::wire<'X',7,'~'>,
    
                    dmm::wire<'Y',0,'~'>, dmm::wire<'Y',1,'~'>, dmm::wire<'Y',2,'~'>, dmm::wire<'Y',3,'~'>,
                    dmm::wire<'Y',4,'~'>, dmm::wire<'Y',5,'~'>, dmm::wire<'Y',6,'~'>, dmm::wire<'Y',7,'~'>,
    
                    dmm::wire<'O',0,'&'>, dmm::wire<'O',1,'&'>, dmm::wire<'O',2,'&'>, dmm::wire<'O',3,'&'>,
                    dmm::wire<'O',4,'&'>, dmm::wire<'O',5,'&'>, dmm::wire<'O',6,'&'>, dmm::wire<'O',7,'&'>
            >,
    
            lib::mux_8_2_1<
                    dmm::wire<'O',0,'&'>, dmm::wire<'O',1,'&'>, dmm::wire<'O',2,'&'>, dmm::wire<'O',3,'&'>,
                    dmm::wire<'O',4,'&'>, dmm::wire<'O',5,'&'>, dmm::wire<'O',6,'&'>, dmm::wire<'O',7,'&'>,
    
                    dmm::wire<'O',0,'+'>, dmm::wire<'O',1,'+'>, dmm::wire<'O',2,'+'>, dmm::wire<'O',3,'+'>,
                    dmm::wire<'O',4,'+'>, dmm::wire<'O',5,'+'>, dmm::wire<'O',6,'+'>, dmm::wire<'O',7,'+'>,
    
                    F*,
    
                    dmm::wire<'O',0,'|'>, dmm::wire<'O',1,'|'>, dmm::wire<'O',2,'|'>, dmm::wire<'O',3,'|'>,
                    dmm::wire<'O',4,'|'>, dmm::wire<'O',5,'|'>, dmm::wire<'O',6,'|'>, dmm::wire<'O',7,'|'>
            >,
    
            negate_or_passthrough<NO*,
                    dmm::wire<'O',0,'|'>, dmm::wire<'O',1,'|'>, dmm::wire<'O',2,'|'>, dmm::wire<'O',3,'|'>,
                    dmm::wire<'O',4,'|'>, dmm::wire<'O',5,'|'>, dmm::wire<'O',6,'|'>, dmm::wire<'O',7,'|'>,
    
                    O0*, O1*, O2*, O3*, O4*, O5*, O6*, O7*
            >,
    
            lib::or_8_1<O0*, O1*, O2*, O3*, O4*, O5*, O6*, O7*, dmm::wire<'Z', '~'>>,
            unit_not<dmm::wire<'Z', '~'>, ZR*>,
    
            unit_buf<O0*, NG*>
    >;
}

#endif //TRIMETA_ALU_HPP
