# Assignment 1 :Circular Buffer


##المخزن الدائري : 

المخزن الدائري (Circular Buffer) هو هيكل بيانات يستخدم مصفوفة ذات حجم ثابت بطريقة دائرية، بحيث يعود مؤشر الكتابة او القراءة إلى بداية المصفوفة تلقائياً عند وصوله إلى النهاية.

### المخزن الخطي والدائري

| المخزن الخطي | المخزن الدائري |
|---|---|
| يُكتب من البداية إلى النهاية ثم ينتهي | يعود المؤشر إلى البداية تلقائياً |
| يهدر المساحة المُقروءة | يُعيد استخدام المساحة المُقروءة |
| يحتاج إعادة ضبط يدوية | يعمل بشكل مستمر ودوري |


## تفاصيل اضافية : 

يعتمد المخزن على 3 عناصر رئيسية:

- **`head`**: مؤشر القراءة — يشير إلى أقدم عنصر في المخزن.
- **`tail`**: مؤشر الكتابة — يشير إلى الموضع التالي المتاح للكتابة.
- **`count`**: عداد يتتبع عدد العناصر الحالية.

الحركة الدورية تتم بالعملية الحسابية:
```
مؤشر جديد = (مؤشر قديم + 1) % حجم المخزن
```

---

## العمليات:

### 1. التهيئة (`init`)
تضبط جميع القيم إلى الصفر

### 2. الكتابة (`write`)
تضيف حرف عند موضع `tail` ثم تُحرّك `tail` للأمام دورياً.
- في **الامتلاء (Overflow)**: تطبع رسالة تحذير وترجع دون كتابة.

### 3. القراءة (`read_cb`)
تقرأ حرف من موضع `head` ثم تُحرّك `head` للأمام دورياً (مبدأ FIFO).
- في حالة **الفراغ (Underflow)**: تطبع رسالة تحذير وترجع `'\0'`.

### 4. isFull / isEmpty
دالتان للتحقق من حالة المخزن قبل أي عملية.

---

### مثال مع مخزن صغير (حجم = 5):
```
Enter name: sana

Full string to store: "sanaCE-ESY" (10 characters)
Buffer size: 5
Writing....
Overflow Buffer is full'E'
Overflow Buffer is full'-'
Overflow Buffer is full'E'
Overflow Buffer is full'S'
Overflow Buffer is full'Y'
Characters stored : 5 / 5
Reading from buffer
Output: sanaC
Buffer is now empty. All data has been read successfully.

Process returned 0 (0x0)   execution time : 4.614 s
```

### مع مخزن كبير (حجم =25):
```
Full string to store: "sana altarabishiCE-ESY" (22 characters)
Buffer size: 25
Writing....
Characters stored : 22 / 25
Reading from buffer
Output: sana altarabishiCE-ESY
Buffer is now empty. All data has been read successfully.

Process returned 0 (0x0)   execution time : 6.560 s
```

---
