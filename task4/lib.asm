global ComplexToReal
global FractionToReal
global PolarToReal
global ShakerSort

extern fwrite
extern atoi
extern fclose
extern fopen
extern strcmp
extern srand
extern time
extern printf
extern fputc
extern fprintf
extern rand
extern sqrtf

extern Complex
extern Polar
extern Fraction
extern Number
extern ToReal

SECTION .text



;float ComplexToReal(struct Complex* complex) {
;    return sqrt(complex->Re*complex->Re + complex->Im*complex->Im);
;}
ComplexToReal:
        movss   xmm0, DWORD [rdi]
        movss   xmm1, DWORD [rdi+4]
        mulss   xmm0, xmm0
        mulss   xmm1, xmm1
        addss   xmm0, xmm1
        pxor    xmm1, xmm1
        ucomiss xmm1, xmm0
        ja      .sqrt
        sqrtss  xmm0, xmm0
        ret
.sqrt:
        jmp     sqrtf

;float FractionToReal(struct Fraction* fraction) {
;    return (float)(fraction->Numerator) / fraction->Denominator;
;}
FractionToReal:
        pxor    xmm0, xmm0
        pxor    xmm1, xmm1
        cvtsi2ss        xmm0, DWORD [rdi]
        cvtsi2ss        xmm1, DWORD [rdi+4]
        divss   xmm0, xmm1
        ret

;float PolarToReal(struct Polar* polar) {
;    return polar->R;
;}
PolarToReal:
        movss   xmm0, DWORD [rdi]
        ret

;void ShakerSort(struct Container* container) {
;    int left = -1;
;    int right = container->Size;
;    int pos = 0;
;    bool isChanged = 0;
;
;    do {
;        isChanged = 0;
;
;        while (pos + 1 < right) {
;            if (ToReal(container->Numbers[pos]) < ToReal(container->Numbers[pos + 1])) {
;                struct Number* temp = container->Numbers[pos];
;                container->Numbers[pos] = container->Numbers[pos + 1];
;                container->Numbers[pos + 1] = temp;
;                isChanged = 1;
;            }
;            ++pos;
;        }
;        --pos;
;        --right;
;
;        while (pos - 1 > left) {
;            if (ToReal(container->Numbers[pos - 1]) < ToReal(container->Numbers[pos])) {
;                struct Number* temp = container->Numbers[pos - 1];
;                container->Numbers[pos - 1] = container->Numbers[pos];
;                container->Numbers[pos] = temp;
;                isChanged = 1;
;            }
;            --pos;
;        }
;        ++pos;
;        ++left;
;    } while (isChanged);
;}
ShakerSort:
        push    r15
        mov     rax, rdi
        xor     edx, edx
        push    r14
        add     rax, 8
        push    r13
        push    r12
        mov     r12d, -1
        push    rbp
        push    rbx
        sub     rsp, 40
        mov     esi, DWORD [rdi]
        mov     QWORD [rsp+8], rdi
        mov     DWORD [rsp+4], esi
        mov     QWORD [rsp+24], rax
.shaker_sort_loop:
        lea     eax, [rdx+1]
        mov     DWORD [rsp+16], eax
        mov     esi, eax
        mov     eax, DWORD [rsp+4]
        cmp     eax, esi
        jle     .start_shaker_sort_loop
        sub     eax, edx
        movsx   rcx, edx
        mov     rsi, QWORD [rsp+8]
        xor     ebx, ebx
        lea     edx, [rax-2]
        mov     rax, QWORD [rsp+24]
        mov     DWORD [rsp+20], edx
        add     rdx, rcx
        lea     r15, [rsi+rcx*8]
        lea     rbp, [rax+rdx*8]
.forward_if:
        mov     r13, QWORD [r15+8]
        mov     rdi, r13
        call    ToReal
        mov     r14, QWORD [r15+16]
        movss   DWORD [rsp], xmm0
        mov     rdi, r14
        call    ToReal
        comiss  xmm0, DWORD [rsp]
        jbe     .forward_loop
        mov     QWORD [r15+8], r14
        mov     ebx, 1
        mov     QWORD [r15+16], r13
.forward_loop:
        add     r15, 8
        cmp     r15, rbp
        jne     .forward_if
        mov     edx, DWORD [rsp+16]
        add     edx, DWORD [rsp+20]
.backward_loop:
        lea     eax, [rdx-2]
        sub     DWORD [rsp+4], 1
        cmp     r12d, eax
        jge     .end_shaker_sort_loop
        mov     rcx, QWORD [rsp+8]
        movsx   rax, edx
        sub     edx, r12d
        sal     rax, 3
        lea     rbp, [rcx-8+rax]
        lea     r15, [rcx+rax]
        lea     eax, [rdx-3]
        sal     rax, 3
        sub     rbp, rax
.backward_if:
        mov     r14, QWORD [r15-8]
        mov     rdi, r14
        call    ToReal
        mov     r13, QWORD [r15]
        movss   DWORD [rsp], xmm0
        mov     rdi, r13
        call    ToReal
        comiss  xmm0, DWORD [rsp]
        jbe     .end_backward_loop
        mov     QWORD [r15-8], r13
        mov     ebx, 1
        mov     QWORD [r15], r14
.end_backward_loop:
        sub     r15, 8
        cmp     r15, rbp
        jne     .backward_if
        lea     edx, [r12+2]
.end_shaker_sort_loop:
        add     r12d, 1
        test    bl, bl
        jne     .shaker_sort_loop
        add     rsp, 40
        pop     rbx
        pop     rbp
        pop     r12
        pop     r13
        pop     r14
        pop     r15
        ret
.start_shaker_sort_loop:
        xor     ebx, ebx
        jmp     .backward_loop