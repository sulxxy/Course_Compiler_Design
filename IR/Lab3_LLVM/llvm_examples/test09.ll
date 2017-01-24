; ModuleID = 'test09.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [13 x i8] c"%d %d %d %d\0A\00", align 1

; Function Attrs: nounwind
define i32 @init() #0 {
  ret i32 42, !dbg !13
}

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %z = alloca i32, align 4
  %t = alloca i32, align 4
  store i32 0, i32* %1
  call void @llvm.dbg.declare(metadata !{i32* %x}, metadata !14), !dbg !15
  store i32 1, i32* %x, align 4, !dbg !15
  call void @llvm.dbg.declare(metadata !{i32* %y}, metadata !16), !dbg !17
  call void @llvm.dbg.declare(metadata !{i32* %z}, metadata !18), !dbg !19
  call void @llvm.dbg.declare(metadata !{i32* %t}, metadata !20), !dbg !21
  %2 = load i32* %x, align 4, !dbg !22
  %3 = load i32* %y, align 4, !dbg !22
  %4 = icmp sgt i32 %2, %3, !dbg !22
  br i1 %4, label %5, label %8, !dbg !22

; <label>:5                                       ; preds = %0
  %6 = load i32* %x, align 4, !dbg !24
  %7 = add nsw i32 5, %6, !dbg !24
  store i32 %7, i32* %y, align 4, !dbg !24
  br label %11, !dbg !26

; <label>:8                                       ; preds = %0
  %9 = call i32 @init(), !dbg !27
  store i32 %9, i32* %y, align 4, !dbg !27
  %10 = call i32 @init(), !dbg !29
  store i32 %10, i32* %t, align 4, !dbg !29
  br label %11

; <label>:11                                      ; preds = %8, %5
  %12 = load i32* %y, align 4, !dbg !30
  %13 = load i32* %y, align 4, !dbg !30
  %14 = mul nsw i32 %12, %13, !dbg !30
  store i32 %14, i32* %z, align 4, !dbg !30
  %15 = load i32* %x, align 4, !dbg !31
  %16 = load i32* %y, align 4, !dbg !31
  %17 = load i32* %z, align 4, !dbg !31
  %18 = load i32* %t, align 4, !dbg !31
  %19 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([13 x i8]* @.str, i32 0, i32 0), i32 %15, i32 %16, i32 %17, i32 %18), !dbg !31
  ret i32 0, !dbg !32
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata) #1

declare i32 @printf(i8*, ...) #2

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!10, !11}
!llvm.ident = !{!12}

!0 = metadata !{i32 786449, metadata !1, i32 12, metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)", i1 false, metadata !"", i32 0, metadata !2, metadata !2, metadata !3, metadata !2, metadata !2, metadata !""} ; [ DW_TAG_compile_unit ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test09.c] [DW_LANG_C99]
!1 = metadata !{metadata !"test09.c", metadata !"/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples"}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4, metadata !9}
!4 = metadata !{i32 786478, metadata !1, metadata !5, metadata !"init", metadata !"init", metadata !"", i32 9, metadata !6, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @init, null, null, metadata !2, i32 9} ; [ DW_TAG_subprogram ] [line 9] [def] [init]
!5 = metadata !{i32 786473, metadata !1}          ; [ DW_TAG_file_type ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test09.c]
!6 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !7, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!7 = metadata !{metadata !8}
!8 = metadata !{i32 786468, null, null, metadata !"int", i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ] [int] [line 0, size 32, align 32, offset 0, enc DW_ATE_signed]
!9 = metadata !{i32 786478, metadata !1, metadata !5, metadata !"main", metadata !"main", metadata !"", i32 14, metadata !6, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @main, null, null, metadata !2, i32 14} ; [ DW_TAG_subprogram ] [line 14] [def] [main]
!10 = metadata !{i32 2, metadata !"Dwarf Version", i32 4}
!11 = metadata !{i32 1, metadata !"Debug Info Version", i32 1}
!12 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
!13 = metadata !{i32 10, i32 0, metadata !4, null}
!14 = metadata !{i32 786688, metadata !9, metadata !"x", metadata !5, i32 15, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [x] [line 15]
!15 = metadata !{i32 15, i32 0, metadata !9, null}
!16 = metadata !{i32 786688, metadata !9, metadata !"y", metadata !5, i32 16, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [y] [line 16]
!17 = metadata !{i32 16, i32 0, metadata !9, null}
!18 = metadata !{i32 786688, metadata !9, metadata !"z", metadata !5, i32 17, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [z] [line 17]
!19 = metadata !{i32 17, i32 0, metadata !9, null}
!20 = metadata !{i32 786688, metadata !9, metadata !"t", metadata !5, i32 18, metadata !8, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [t] [line 18]
!21 = metadata !{i32 18, i32 0, metadata !9, null}
!22 = metadata !{i32 20, i32 0, metadata !23, null}
!23 = metadata !{i32 786443, metadata !1, metadata !9, i32 20, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test09.c]
!24 = metadata !{i32 21, i32 0, metadata !25, null}
!25 = metadata !{i32 786443, metadata !1, metadata !23, i32 20, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test09.c]
!26 = metadata !{i32 22, i32 0, metadata !25, null}
!27 = metadata !{i32 24, i32 0, metadata !28, null}
!28 = metadata !{i32 786443, metadata !1, metadata !23, i32 23, i32 0, i32 2} ; [ DW_TAG_lexical_block ] [/home/zhiwei/project/Course_Compiler_Design/IR/Lab3_LLVM/llvm_examples/test09.c]
!29 = metadata !{i32 25, i32 0, metadata !28, null}
!30 = metadata !{i32 27, i32 0, metadata !9, null}
!31 = metadata !{i32 29, i32 0, metadata !9, null}
!32 = metadata !{i32 31, i32 0, metadata !9, null}
