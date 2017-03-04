; ModuleID = 'test05.bc'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %count = alloca i32, align 4
  store i32 0, i32* %1
  call void @llvm.dbg.declare(metadata !{i32* %count}, metadata !12), !dbg !13
  br label %2, !dbg !14

; <label>:2                                       ; preds = %5, %0
  %3 = load i32* %count, align 4, !dbg !15
  %4 = icmp slt i32 %3, 100, !dbg !15
  br i1 %4, label %5, label %8, !dbg !15

; <label>:5                                       ; preds = %2
  %6 = load i32* %count, align 4, !dbg !17
  %7 = add nsw i32 %6, 1, !dbg !17
  store i32 %7, i32* %count, align 4, !dbg !17
  br label %2, !dbg !19

; <label>:8                                       ; preds = %2
  %9 = load i32* %count, align 4, !dbg !20
  %10 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0), i32 %9), !dbg !20
  ret i32 0, !dbg !21
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

!0 = metadata !{i32 786449, metadata !1, i32 12, metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)", i1 false, metadata !"", i32 0, metadata !2, metadata !2, metadata !3, metadata !2, metadata !2, metadata !"", i32 1} ; [ DW_TAG_compile_unit ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test05.c] [DW_LANG_C99]
!1 = metadata !{metadata !"test05.c", metadata !"/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples"}
!2 = metadata !{}
!3 = metadata !{metadata !4}
!4 = metadata !{i32 786478, metadata !1, metadata !5, metadata !"main", metadata !"main", metadata !"", i32 6, metadata !6, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @main, null, null, metadata !2, i32 7} ; [ DW_TAG_subprogram ] [line 6] [def] [scope 7] [main]
!5 = metadata !{i32 786473, metadata !1}          ; [ DW_TAG_file_type ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test05.c]
!6 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !7, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!7 = metadata !{metadata !8}
!8 = metadata !{i32 786468, null, null, metadata !"int", i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ] [int] [line 0, size 32, align 32, offset 0, enc DW_ATE_signed]
!9 = metadata !{i32 2, metadata !"Dwarf Version", i32 4}
!10 = metadata !{i32 2, metadata !"Debug Info Version", i32 1}
!11 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
!12 = metadata !{i32 786688, metadata !4, metadata !"count", metadata !5, i32 8, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [count] [line 8]
!13 = metadata !{i32 8, i32 9, metadata !4, null} ; [ DW_TAG_imported_declaration ]
!14 = metadata !{i32 10, i32 5, metadata !4, null}
!15 = metadata !{i32 10, i32 5, metadata !16, null}
!16 = metadata !{i32 786443, metadata !1, metadata !4, i32 10, i32 5, i32 1, i32 1} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test05.c]
!17 = metadata !{i32 12, i32 9, metadata !18, null}
!18 = metadata !{i32 786443, metadata !1, metadata !4, i32 11, i32 5, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test05.c]
!19 = metadata !{i32 13, i32 5, metadata !18, null}
!20 = metadata !{i32 15, i32 5, metadata !4, null}
!21 = metadata !{i32 17, i32 5, metadata !4, null}
