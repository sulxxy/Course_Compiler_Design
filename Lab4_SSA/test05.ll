; ModuleID = 'test05.bc'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [7 x i8] c"%d %d\0A\00", align 1

; Function Attrs: nounwind
define void @test(i32 %pred, i32 %pred2) #0 {
  %1 = icmp ne i32 %pred, 0
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = add nsw i32 1, 2
  %4 = add nsw i32 -1, %3
  br label %10

; <label>:5                                       ; preds = %0
  br label %6

; <label>:6                                       ; preds = %10, %5
  %i.0 = phi i32 [ %11, %10 ], [ 1, %5 ]
  %j.0 = phi i32 [ %12, %10 ], [ 0, %5 ]
  %7 = icmp slt i32 %j.0, 10
  br i1 %7, label %8, label %13

; <label>:8                                       ; preds = %6
  %9 = add nsw i32 %i.0, 1
  br label %10

; <label>:10                                      ; preds = %8, %2
  %j.1 = phi i32 [ 0, %2 ], [ %j.0, %8 ]
  %k.0 = phi i32 [ %4, %2 ], [ %9, %8 ]
  %11 = sub nsw i32 %k.0, 1
  %12 = add nsw i32 %j.1, 1
  br label %6

; <label>:13                                      ; preds = %6
  %14 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([7 x i8]* @.str, i32 0, i32 0), i32 %i.0, i32 %j.0)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind
define i32 @main() #0 {
  call void @test(i32 0, i32 1)
  ret i32 0
}

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
