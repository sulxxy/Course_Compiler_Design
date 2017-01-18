; ModuleID = 'example2.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [14 x i8] c"result is %d\0A\00", align 1

; Function Attrs: nounwind
define void @fun_a() #0 {
  ret void
}

; Function Attrs: nounwind
define i32 @fun_b(i32 %a, i32 %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 %b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %1, align 4
  %5 = mul nsw i32 %3, %4
  %6 = load i32* %2, align 4
  %7 = add nsw i32 %5, %6
  ret i32 %7
}

; Function Attrs: nounwind
define i32 @fun_c(i32 %a, i32 %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %r = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 %b, i32* %2, align 4
  store i32 0, i32* %r, align 4
  store i32 0, i32* %i, align 4
  br label %3

; <label>:3                                       ; preds = %13, %0
  %4 = load i32* %i, align 4
  %5 = load i32* %1, align 4
  %6 = icmp slt i32 %4, %5
  br i1 %6, label %7, label %16

; <label>:7                                       ; preds = %3
  %8 = load i32* %2, align 4
  %9 = load i32* %i, align 4
  %10 = mul nsw i32 %8, %9
  %11 = load i32* %r, align 4
  %12 = add nsw i32 %11, %10
  store i32 %12, i32* %r, align 4
  br label %13

; <label>:13                                      ; preds = %7
  %14 = load i32* %i, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %i, align 4
  br label %3

; <label>:16                                      ; preds = %3
  %17 = load i32* %r, align 4
  ret i32 %17
}

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca i32, align 4
  %d = alloca i32, align 4
  %e = alloca i32, align 4
  %f = alloca i32, align 4
  store i32 0, i32* %1
  store i32 10, i32* %a, align 4
  store i32 30, i32* %b, align 4
  call void @fun_a()
  %2 = load i32* %a, align 4
  %3 = load i32* %b, align 4
  %4 = call i32 @fun_b(i32 %2, i32 %3)
  store i32 %4, i32* %c, align 4
  %5 = load i32* %a, align 4
  %6 = load i32* %b, align 4
  %7 = call i32 @fun_c(i32 %5, i32 %6)
  store i32 %7, i32* %d, align 4
  %8 = load i32* %a, align 4
  %9 = load i32* %a, align 4
  %10 = call i32 @fun_b(i32 %8, i32 %9)
  store i32 %10, i32* %e, align 4
  %11 = load i32* %c, align 4
  %12 = load i32* %d, align 4
  %13 = call i32 @fun_b(i32 %11, i32 %12)
  store i32 %13, i32* %f, align 4
  %14 = load i32* %f, align 4
  %15 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @.str, i32 0, i32 0), i32 %14)
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
