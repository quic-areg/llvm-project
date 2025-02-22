// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 5
// REQUIRES: aarch64-registered-target

// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sme -target-feature +sme-f8f16 -target-feature +sme-f8f32 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sme -target-feature +sme-f8f16 -target-feature +sme-f8f32 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sme -target-feature +sme-f8f16 -target-feature +sme-f8f32 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sme -target-feature +sme-f8f16 -target-feature +sme-f8f32 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sme -target-feature +sme-f8f16 -target-feature +sme-f8f32 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sme.h>

#ifdef SVE_OVERLOADED_FORMS
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3) A1##A2##A3
#endif


// CHECK-LABEL: define dso_local void @test_svmopa_za16_mf8_m(
// CHECK-SAME: <vscale x 16 x i1> [[PN:%.*]], <vscale x 16 x i1> [[PM:%.*]], <vscale x 16 x i8> [[ZN:%.*]], <vscale x 16 x i8> [[ZM:%.*]], i64 noundef [[FPMR:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    tail call void @llvm.aarch64.set.fpmr(i64 [[FPMR]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fp8.fmopa.za16(i32 1, <vscale x 16 x i1> [[PN]], <vscale x 16 x i1> [[PM]], <vscale x 16 x i8> [[ZN]], <vscale x 16 x i8> [[ZM]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: define dso_local void @_Z22test_svmopa_za16_mf8_mu10__SVBool_tS_u13__SVMfloat8_tS0_m(
// CPP-CHECK-SAME: <vscale x 16 x i1> [[PN:%.*]], <vscale x 16 x i1> [[PM:%.*]], <vscale x 16 x i8> [[ZN:%.*]], <vscale x 16 x i8> [[ZM:%.*]], i64 noundef [[FPMR:%.*]]) #[[ATTR0:[0-9]+]] {
// CPP-CHECK-NEXT:  [[ENTRY:.*:]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.set.fpmr(i64 [[FPMR]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fp8.fmopa.za16(i32 1, <vscale x 16 x i1> [[PN]], <vscale x 16 x i1> [[PM]], <vscale x 16 x i8> [[ZN]], <vscale x 16 x i8> [[ZM]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmopa_za16_mf8_m(svbool_t pn, svbool_t pm, svmfloat8_t zn,
                            svmfloat8_t zm, fpm_t fpmr) __arm_streaming __arm_inout("za") {
  SVE_ACLE_FUNC(svmopa_za16,_mf8,_m_fpm)(1, pn, pm, zn, zm, fpmr);
}

// CHECK-LABEL: define dso_local void @test_svmopa_za32_mf8_m(
// CHECK-SAME: <vscale x 16 x i1> [[PN:%.*]], <vscale x 16 x i1> [[PM:%.*]], <vscale x 16 x i8> [[ZN:%.*]], <vscale x 16 x i8> [[ZM:%.*]], i64 noundef [[FPMR:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    tail call void @llvm.aarch64.set.fpmr(i64 [[FPMR]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fp8.fmopa.za32(i32 3, <vscale x 16 x i1> [[PN]], <vscale x 16 x i1> [[PM]], <vscale x 16 x i8> [[ZN]], <vscale x 16 x i8> [[ZM]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: define dso_local void @_Z22test_svmopa_za32_mf8_mu10__SVBool_tS_u13__SVMfloat8_tS0_m(
// CPP-CHECK-SAME: <vscale x 16 x i1> [[PN:%.*]], <vscale x 16 x i1> [[PM:%.*]], <vscale x 16 x i8> [[ZN:%.*]], <vscale x 16 x i8> [[ZM:%.*]], i64 noundef [[FPMR:%.*]]) #[[ATTR0]] {
// CPP-CHECK-NEXT:  [[ENTRY:.*:]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.set.fpmr(i64 [[FPMR]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fp8.fmopa.za32(i32 3, <vscale x 16 x i1> [[PN]], <vscale x 16 x i1> [[PM]], <vscale x 16 x i8> [[ZN]], <vscale x 16 x i8> [[ZM]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmopa_za32_mf8_m(svbool_t pn, svbool_t pm, svmfloat8_t zn,
                            svmfloat8_t zm, fpm_t fpmr) __arm_streaming __arm_inout("za") {
  SVE_ACLE_FUNC(svmopa_za32,_mf8,_m_fpm)(3, pn, pm, zn, zm, fpmr);
}
