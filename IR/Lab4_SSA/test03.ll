; ModuleID = 'test03.bc'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [7 x i8] c"%d %d\0A\00", align 1

; Function Attrs: nounwind
define void @test(i32 %pred) #0 {
  %1 = icmp ne i32 %pred, 0
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = add nsw i32 1, 1
  %4 = sub nsw i32 1, 1
  br label %8

; <label>:5                                       ; preds = %0
  %6 = sub nsw i32 3, 1
  %7 = add nsw i32 3, 1
  br label %8

; <label>:8                                       ; preds = %5, %2
  %k.0 = phi i32 [ %3, %2 ], [ %6, %5 ]
  %l.0 = phi i32 [ %4, %2 ], [ %7, %5 ]
  %9 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([7 x i8]* @.str, i32 0, i32 0), i32 %k.0, i32 %l.0)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind
define i32 @main() #0 {
  call void @test(i32 1)
  ret i32 0
}

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
