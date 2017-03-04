; ModuleID = 'test08.bc'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [22 x i8] c"%d %d %d %d %d %f %f\0A\00", align 1

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca i32, align 4
  %d = alloca i32, align 4
  %e = alloca i32, align 4
  %f = alloca float, align 4
  %g = alloca double, align 8
  %i = alloca i32, align 4
  store i32 0, i32* %1
  call void @llvm.dbg.declare(metadata !{i32* %a}, metadata !12), !dbg !13
  call void @llvm.dbg.declare(metadata !{i32* %b}, metadata !14), !dbg !15
  call void @llvm.dbg.declare(metadata !{i32* %c}, metadata !16), !dbg !17
  call void @llvm.dbg.declare(metadata !{i32* %d}, metadata !18), !dbg !19
  call void @llvm.dbg.declare(metadata !{i32* %e}, metadata !20), !dbg !21
  call void @llvm.dbg.declare(metadata !{float* %f}, metadata !22), !dbg !24
  call void @llvm.dbg.declare(metadata !{double* %g}, metadata !25), !dbg !27
  %2 = load i32* %a, align 4, !dbg !28
  %3 = icmp sgt i32 %2, 100, !dbg !28
  br i1 %3, label %4, label %5, !dbg !28

; <label>:4                                       ; preds = %0
  store i32 10, i32* %a, align 4, !dbg !30
  br label %6, !dbg !32

; <label>:5                                       ; preds = %0
  store i32 20, i32* %a, align 4, !dbg !33
  store i32 20, i32* %b, align 4, !dbg !35
  br label %6

; <label>:6                                       ; preds = %5, %4
  %7 = load i32* %e, align 4, !dbg !36
  %8 = mul nsw i32 %7, 100, !dbg !36
  store i32 %8, i32* %e, align 4, !dbg !36
  %9 = load i32* %c, align 4, !dbg !37
  %10 = mul nsw i32 %9, 2, !dbg !37
  store i32 %10, i32* %d, align 4, !dbg !37
  call void @llvm.dbg.declare(metadata !{i32* %i}, metadata !38), !dbg !40
  store i32 0, i32* %i, align 4, !dbg !41
  br label %11, !dbg !41

; <label>:11                                      ; preds = %24, %6
  %12 = load i32* %i, align 4, !dbg !42
  %13 = load i32* %a, align 4, !dbg !42
  %14 = icmp slt i32 %12, %13, !dbg !42
  br i1 %14, label %15, label %27, !dbg !42

; <label>:15                                      ; preds = %11
  %16 = load i32* %i, align 4, !dbg !45
  %17 = load i32* %a, align 4, !dbg !45
  %18 = icmp slt i32 %16, %17, !dbg !45
  br i1 %18, label %19, label %22, !dbg !45

; <label>:19                                      ; preds = %15
  %20 = load double* %g, align 8, !dbg !48
  %21 = fadd double %20, 1.000000e+00, !dbg !48
  store double %21, double* %g, align 8, !dbg !48
  br label %23, !dbg !50

; <label>:22                                      ; preds = %15
  store double 5.000000e+02, double* %g, align 8, !dbg !51
  br label %23

; <label>:23                                      ; preds = %22, %19
  br label %24, !dbg !53

; <label>:24                                      ; preds = %23
  %25 = load i32* %i, align 4, !dbg !54
  %26 = add nsw i32 %25, 1, !dbg !54
  store i32 %26, i32* %i, align 4, !dbg !54
  br label %11, !dbg !54

; <label>:27                                      ; preds = %11
  %28 = load i32* %a, align 4, !dbg !55
  %29 = load i32* %b, align 4, !dbg !55
  %30 = load i32* %c, align 4, !dbg !55
  %31 = load i32* %d, align 4, !dbg !55
  %32 = load i32* %e, align 4, !dbg !55
  %33 = load float* %f, align 4, !dbg !55
  %34 = fpext float %33 to double, !dbg !55
  %35 = load double* %g, align 8, !dbg !55
  %36 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([22 x i8]* @.str, i32 0, i32 0), i32 %28, i32 %29, i32 %30, i32 %31, i32 %32, double %34, double %35), !dbg !55
  ret i32 0, !dbg !56
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

!0 = metadata !{i32 786449, metadata !1, i32 12, metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)", i1 false, metadata !"", i32 0, metadata !2, metadata !2, metadata !3, metadata !2, metadata !2, metadata !"", i32 1} ; [ DW_TAG_compile_unit ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c] [DW_LANG_C99]
!1 = metadata !{metadata !"test08.c", metadata !"/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples"}
!2 = metadata !{}
!3 = metadata !{metadata !4}
!4 = metadata !{i32 786478, metadata !1, metadata !5, metadata !"main", metadata !"main", metadata !"", i32 7, metadata !6, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @main, null, null, metadata !2, i32 8} ; [ DW_TAG_subprogram ] [line 7] [def] [scope 8] [main]
!5 = metadata !{i32 786473, metadata !1}          ; [ DW_TAG_file_type ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!6 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !7, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!7 = metadata !{metadata !8}
!8 = metadata !{i32 786468, null, null, metadata !"int", i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ] [int] [line 0, size 32, align 32, offset 0, enc DW_ATE_signed]
!9 = metadata !{i32 2, metadata !"Dwarf Version", i32 4}
!10 = metadata !{i32 2, metadata !"Debug Info Version", i32 1}
!11 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
!12 = metadata !{i32 786688, metadata !4, metadata !"a", metadata !5, i32 9, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [a] [line 9]
!13 = metadata !{i32 9, i32 9, metadata !4, null}
!14 = metadata !{i32 786688, metadata !4, metadata !"b", metadata !5, i32 9, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [b] [line 9]
!15 = metadata !{i32 9, i32 12, metadata !4, null}
!16 = metadata !{i32 786688, metadata !4, metadata !"c", metadata !5, i32 9, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [c] [line 9]
!17 = metadata !{i32 9, i32 15, metadata !4, null}
!18 = metadata !{i32 786688, metadata !4, metadata !"d", metadata !5, i32 9, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [d] [line 9]
!19 = metadata !{i32 9, i32 18, metadata !4, null}
!20 = metadata !{i32 786688, metadata !4, metadata !"e", metadata !5, i32 9, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [e] [line 9]
!21 = metadata !{i32 9, i32 21, metadata !4, null}
!22 = metadata !{i32 786688, metadata !4, metadata !"f", metadata !5, i32 10, metadata !23, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [f] [line 10]
!23 = metadata !{i32 786468, null, null, metadata !"float", i32 0, i64 32, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ] [float] [line 0, size 32, align 32, offset 0, enc DW_ATE_float]
!24 = metadata !{i32 10, i32 11, metadata !4, null}
!25 = metadata !{i32 786688, metadata !4, metadata !"g", metadata !5, i32 11, metadata !26, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [g] [line 11]
!26 = metadata !{i32 786468, null, null, metadata !"double", i32 0, i64 64, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ] [double] [line 0, size 64, align 32, offset 0, enc DW_ATE_float]
!27 = metadata !{i32 11, i32 12, metadata !4, null}
!28 = metadata !{i32 13, i32 8, metadata !29, null}
!29 = metadata !{i32 786443, metadata !1, metadata !4, i32 13, i32 8, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!30 = metadata !{i32 14, i32 9, metadata !31, null}
!31 = metadata !{i32 786443, metadata !1, metadata !29, i32 13, i32 16, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!32 = metadata !{i32 15, i32 5, metadata !31, null}
!33 = metadata !{i32 17, i32 9, metadata !34, null}
!34 = metadata !{i32 786443, metadata !1, metadata !29, i32 16, i32 10, i32 0, i32 2} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!35 = metadata !{i32 18, i32 9, metadata !34, null}
!36 = metadata !{i32 21, i32 5, metadata !4, null}
!37 = metadata !{i32 22, i32 5, metadata !4, null}
!38 = metadata !{i32 786688, metadata !39, metadata !"i", metadata !5, i32 24, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [i] [line 24]
!39 = metadata !{i32 786443, metadata !1, metadata !4, i32 24, i32 5, i32 0, i32 3} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!40 = metadata !{i32 24, i32 14, metadata !39, null}
!41 = metadata !{i32 24, i32 10, metadata !39, null}
!42 = metadata !{i32 24, i32 10, metadata !43, null}
!43 = metadata !{i32 786443, metadata !1, metadata !44, i32 24, i32 10, i32 2, i32 9} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!44 = metadata !{i32 786443, metadata !1, metadata !39, i32 24, i32 10, i32 1, i32 8} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!45 = metadata !{i32 26, i32 12, metadata !46, null}
!46 = metadata !{i32 786443, metadata !1, metadata !47, i32 26, i32 12, i32 0, i32 5} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!47 = metadata !{i32 786443, metadata !1, metadata !39, i32 25, i32 5, i32 0, i32 4} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!48 = metadata !{i32 27, i32 13, metadata !49, null}
!49 = metadata !{i32 786443, metadata !1, metadata !46, i32 26, i32 16, i32 0, i32 6} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!50 = metadata !{i32 28, i32 9, metadata !49, null}
!51 = metadata !{i32 30, i32 13, metadata !52, null}
!52 = metadata !{i32 786443, metadata !1, metadata !46, i32 29, i32 14, i32 0, i32 7} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test08.c]
!53 = metadata !{i32 32, i32 5, metadata !47, null}
!54 = metadata !{i32 24, i32 28, metadata !39, null}
!55 = metadata !{i32 34, i32 5, metadata !4, null}
!56 = metadata !{i32 36, i32 5, metadata !4, null}
