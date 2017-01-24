; ModuleID = 'test04.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [13 x i8] c"%d %d %f %f\0A\00", align 1

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %k = alloca i32, align 4
  %i = alloca i32, align 4
  %f = alloca float, align 4
  %d = alloca double, align 8
  store i32 0, i32* %1
  call void @llvm.dbg.declare(metadata !{i32* %k}, metadata !12), !dbg !13
  call void @llvm.dbg.declare(metadata !{i32* %i}, metadata !14), !dbg !13
  call void @llvm.dbg.declare(metadata !{float* %f}, metadata !15), !dbg !17
  call void @llvm.dbg.declare(metadata !{double* %d}, metadata !18), !dbg !20
  store i32 0, i32* %i, align 4, !dbg !21
  br label %2, !dbg !21

; <label>:2                                       ; preds = %14, %0
  %3 = load i32* %i, align 4, !dbg !21
  %4 = icmp slt i32 %3, 10, !dbg !21
  br i1 %4, label %5, label %17, !dbg !21

; <label>:5                                       ; preds = %2
  %6 = load i32* %k, align 4, !dbg !23
  %7 = add nsw i32 %6, 10, !dbg !23
  store i32 %7, i32* %k, align 4, !dbg !23
  %8 = load float* %f, align 4, !dbg !25
  %9 = fpext float %8 to double, !dbg !25
  %10 = fadd double %9, 1.000000e-01, !dbg !25
  %11 = fptrunc double %10 to float, !dbg !25
  store float %11, float* %f, align 4, !dbg !25
  %12 = load double* %d, align 8, !dbg !26
  %13 = fadd double %12, 2.000000e-01, !dbg !26
  store double %13, double* %d, align 8, !dbg !26
  br label %14, !dbg !27

; <label>:14                                      ; preds = %5
  %15 = load i32* %i, align 4, !dbg !21
  %16 = add nsw i32 %15, 1, !dbg !21
  store i32 %16, i32* %i, align 4, !dbg !21
  br label %2, !dbg !21

; <label>:17                                      ; preds = %2
  %18 = load i32* %k, align 4, !dbg !28
  %19 = load i32* %i, align 4, !dbg !28
  %20 = load float* %f, align 4, !dbg !28
  %21 = fpext float %20 to double, !dbg !28
  %22 = load double* %d, align 8, !dbg !28
  %23 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([13 x i8]* @.str, i32 0, i32 0), i32 %18, i32 %19, double %21, double %22), !dbg !28
  ret i32 0, !dbg !29
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata) #1

declare i32 @printf(i8*, ...) #2

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!9, !10}
!llvm.ident = !{!11}

!0 = metadata !{i32 786449, metadata !1, i32 12, metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)", i1 false, metadata !"", i32 0, metadata !2, metadata !2, metadata !3, metadata !2, metadata !2, metadata !""} ; [ DW_TAG_compile_unit ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test04.c] [DW_LANG_C99]
!1 = metadata !{metadata !"test04.c", metadata !"/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples"}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{i32 786478, metadata !1, metadata !5, metadata !"main", metadata !"main", metadata !"", i32 6, metadata !6, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @main, null, null, metadata !2, i32 7} ; [ DW_TAG_subprogram ] [line 6] [def] [scope 7] [main]
!5 = metadata !{i32 786473, metadata !1}          ; [ DW_TAG_file_type ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test04.c]
!6 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !7, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!7 = metadata !{metadata !8}
!8 = metadata !{i32 786468, null, null, metadata !"int", i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ] [int] [line 0, size 32, align 32, offset 0, enc DW_ATE_signed]
!9 = metadata !{i32 2, metadata !"Dwarf Version", i32 4}
!10 = metadata !{i32 1, metadata !"Debug Info Version", i32 1}
!11 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
!12 = metadata !{i32 786688, metadata !4, metadata !"k", metadata !5, i32 8, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [k] [line 8]
!13 = metadata !{i32 8, i32 0, metadata !4, null} ; [ DW_TAG_imported_declaration ]
!14 = metadata !{i32 786688, metadata !4, metadata !"i", metadata !5, i32 8, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [i] [line 8]
!15 = metadata !{i32 786688, metadata !4, metadata !"f", metadata !5, i32 9, metadata !16, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [f] [line 9]
!16 = metadata !{i32 786468, null, null, metadata !"float", i32 0, i64 32, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ] [float] [line 0, size 32, align 32, offset 0, enc DW_ATE_float]
!17 = metadata !{i32 9, i32 0, metadata !4, null}
!18 = metadata !{i32 786688, metadata !4, metadata !"d", metadata !5, i32 10, metadata !19, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [d] [line 10]
!19 = metadata !{i32 786468, null, null, metadata !"double", i32 0, i64 64, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ] [double] [line 0, size 64, align 32, offset 0, enc DW_ATE_float]
!20 = metadata !{i32 10, i32 0, metadata !4, null}
!21 = metadata !{i32 12, i32 0, metadata !22, null}
!22 = metadata !{i32 786443, metadata !1, metadata !4, i32 12, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test04.c]
!23 = metadata !{i32 14, i32 0, metadata !24, null}
!24 = metadata !{i32 786443, metadata !1, metadata !22, i32 13, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test04.c]
!25 = metadata !{i32 15, i32 0, metadata !24, null}
!26 = metadata !{i32 16, i32 0, metadata !24, null}
!27 = metadata !{i32 17, i32 0, metadata !24, null}
!28 = metadata !{i32 19, i32 0, metadata !4, null}
!29 = metadata !{i32 21, i32 0, metadata !4, null}
