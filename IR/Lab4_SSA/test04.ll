; ModuleID = 'test04.bc'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [7 x i8] c"%d %d\0A\00", align 1

; Function Attrs: nounwind
define i32 @main() #0 {
  br label %1

; <label>:1                                       ; preds = %3, %0
  %i.0 = phi i32 [ 1, %0 ], [ %5, %3 ]
  %j.0 = phi i32 [ 0, %0 ], [ %6, %3 ]
  %2 = icmp slt i32 %j.0, 10
  br i1 %2, label %3, label %7

; <label>:3                                       ; preds = %1
  %4 = add nsw i32 %i.0, 1
  %5 = sub nsw i32 %4, 1
  %6 = add nsw i32 %j.0, 1
  br label %1

; <label>:7                                       ; preds = %1
  %8 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([7 x i8]* @.str, i32 0, i32 0), i32 %i.0, i32 %j.0)
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
