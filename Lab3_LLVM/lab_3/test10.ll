; ModuleID = 'test10.bc'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [7 x i8] c"%f %f\0A\00", align 1

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1
  call void @test(float 2.400000e+01, float 4.200000e+01), !dbg !16
  call void @test(float 4.200000e+01, float 2.400000e+01), !dbg !17
  ret i32 0, !dbg !18
}

; Function Attrs: nounwind
define internal void @test(float %a, float %b) #0 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  %c = alloca float, align 4
  %d = alloca float, align 4
  store float %a, float* %1, align 4
  call void @llvm.dbg.declare(metadata !{float* %1}, metadata !19), !dbg !20
  store float %b, float* %2, align 4
  call void @llvm.dbg.declare(metadata !{float* %2}, metadata !21), !dbg !22
  call void @llvm.dbg.declare(metadata !{float* %c}, metadata !23), !dbg !24
  call void @llvm.dbg.declare(metadata !{float* %d}, metadata !25), !dbg !26
  %3 = load float* %1, align 4, !dbg !27
  %4 = load float* %2, align 4, !dbg !27
  %5 = fcmp olt float %3, %4, !dbg !27
  br i1 %5, label %6, label %7, !dbg !27

; <label>:6                                       ; preds = %0
  store float 1.000000e+00, float* %c, align 4, !dbg !29
  store float 2.000000e+00, float* %d, align 4, !dbg !31
  br label %7, !dbg !32

; <label>:7                                       ; preds = %6, %0
  %8 = load float* %c, align 4, !dbg !33
  %9 = fpext float %8 to double, !dbg !33
  %10 = load float* %d, align 4, !dbg !33
  %11 = fpext float %10 to double, !dbg !33
  %12 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([7 x i8]* @.str, i32 0, i32 0), double %9, double %11), !dbg !33
  ret void, !dbg !34
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata) #1

declare i32 @printf(i8*, ...) #2

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!13, !14}
!llvm.ident = !{!15}

!0 = metadata !{i32 786449, metadata !1, i32 12, metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)", i1 false, metadata !"", i32 0, metadata !2, metadata !2, metadata !3, metadata !2, metadata !2, metadata !"", i32 1} ; [ DW_TAG_compile_unit ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/lab_3/test10.c] [DW_LANG_C99]
!1 = metadata !{metadata !"test10.c", metadata !"/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/lab_3"}
!2 = metadata !{}
!3 = metadata !{metadata !4, metadata !9}
!4 = metadata !{i32 786478, metadata !1, metadata !5, metadata !"main", metadata !"main", metadata !"", i32 19, metadata !6, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @main, null, null, metadata !2, i32 20} ; [ DW_TAG_subprogram ] [line 19] [def] [scope 20] [main]
!5 = metadata !{i32 786473, metadata !1}          ; [ DW_TAG_file_type ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/lab_3/test10.c]
!6 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !7, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!7 = metadata !{metadata !8}
!8 = metadata !{i32 786468, null, null, metadata !"int", i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ] [int] [line 0, size 32, align 32, offset 0, enc DW_ATE_signed]
!9 = metadata !{i32 786478, metadata !1, metadata !5, metadata !"test", metadata !"test", metadata !"", i32 7, metadata !10, i1 true, i1 true, i32 0, i32 0, null, i32 256, i1 false, void (float, float)* @test, null, null, metadata !2, i32 8} ; [ DW_TAG_subprogram ] [line 7] [local] [def] [scope 8] [test]
!10 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !11, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!11 = metadata !{null, metadata !12, metadata !12}
!12 = metadata !{i32 786468, null, null, metadata !"float", i32 0, i64 32, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ] [float] [line 0, size 32, align 32, offset 0, enc DW_ATE_float]
!13 = metadata !{i32 2, metadata !"Dwarf Version", i32 4}
!14 = metadata !{i32 2, metadata !"Debug Info Version", i32 1}
!15 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
!16 = metadata !{i32 21, i32 5, metadata !4, null}
!17 = metadata !{i32 22, i32 5, metadata !4, null}
!18 = metadata !{i32 23, i32 5, metadata !4, null}
!19 = metadata !{i32 786689, metadata !9, metadata !"a", metadata !5, i32 16777223, metadata !12, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [a] [line 7]
!20 = metadata !{i32 7, i32 24, metadata !9, null}
!21 = metadata !{i32 786689, metadata !9, metadata !"b", metadata !5, i32 33554439, metadata !12, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [b] [line 7]
!22 = metadata !{i32 7, i32 33, metadata !9, null}
!23 = metadata !{i32 786688, metadata !9, metadata !"c", metadata !5, i32 9, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [c] [line 9]
!24 = metadata !{i32 9, i32 11, metadata !9, null}
!25 = metadata !{i32 786688, metadata !9, metadata !"d", metadata !5, i32 9, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [d] [line 9]
!26 = metadata !{i32 9, i32 14, metadata !9, null}
!27 = metadata !{i32 11, i32 9, metadata !28, null}
!28 = metadata !{i32 786443, metadata !1, metadata !9, i32 11, i32 9, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/lab_3/test10.c]
!29 = metadata !{i32 12, i32 9, metadata !30, null}
!30 = metadata !{i32 786443, metadata !1, metadata !28, i32 11, i32 16, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/lab_3/test10.c]
!31 = metadata !{i32 13, i32 9, metadata !30, null}
!32 = metadata !{i32 14, i32 5, metadata !30, null}
!33 = metadata !{i32 16, i32 5, metadata !9, null}
!34 = metadata !{i32 17, i32 1, metadata !9, null}
