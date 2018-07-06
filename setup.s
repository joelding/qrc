	.global	semihosted
	.equ	semihosted,	0
	.equ	stack_size	0x00000400
	.equ	heap_size	0x00000000

	.section	isr_vector	
	.align	2	/* on an address divisible by 4 (that's 1 << 2) */
	.long	_stack	/* 0x00000000 The initial stack pointer (defined by the linker-script) */
	.long	Reset_Handler	/* 0x00000004 The startup-code, the code that runs on power-on or RESET */
	.long	NMI_Handler	/* 0x00000008 Non-Masktable Interrupt, this can not be stopped, preempted or prevented */
	.long	HardFault_Handler	/* 0x0000000c Hard Fault, all classes of Fault */
	.long	0	/* 0x00000010 */
	.long	0	/* 0x00000014 */
	.long	0	/* 0x00000018 */
	.long	0	/* 0x0000001c */
	.long	0	/* 0x00000020 */
	.long	0	/* 0x00000024 */
	.long	0	/* 0x00000028 */
	.long	SVC_Handler	/* 0x0000002c Supervisor Call */
	.long	0	/* 0x00000030 */
	.long	0	/* 0x00000034 */
	.long   PendSV_Handler	/* 0x00000038 Pending Service, pending requests for system service */
	.long	SysTick_Handler	/* 0x0000003c System Tick Timer */

	/* External Interrupts; maximum of 32 External Interrupts are possible */
	.long	BOD_IRQHandler  
	.long	WDT_IRQHandler  
	.long	EINT0_IRQHandler
	.long	EINT1_IRQHandler
	.long	GPAB_IRQHandler 
	.long	GPCDE_IRQHandler
	.long	PWMA_IRQHandler 
	.long	PWMB_IRQHandler 
	.long	TMR0_IRQHandler 
	.long	TMR1_IRQHandler 
	.long	TMR2_IRQHandler 
	.long	TMR3_IRQHandler 
	.long	UART02_IRQHandler
	.long	UART1_IRQHandler
	.long	SPI0_IRQHandler 
	.long	SPI1_IRQHandler 
	.long	SPI2_IRQHandler 
	.long	SPI3_IRQHandler 
	.long	I2C0_IRQHandler 
	.long	I2C1_IRQHandler 
	.long	CAN0_IRQHandler 
	.long	Default_Handler
	.long	Default_Handler 
	.long	USBD_IRQHandler  
	.long	PS2_IRQHandler  
	.long	ACMP_IRQHandler 
	.long	PDMA_IRQHandler
	.long	I2S_IRQHandler 
	.long	PWRWU_IRQHandler
	.long	ADC_IRQHandler
	.long	Default_Handler  
	.long	RTC_IRQHandler  

	.func	Reset_Handler
		.weak	Reset_Handler
	
		ldr	r0, =0x50000100
		/* unlock register */
		ldr	r1, =0x59
		str	r1, [r0]
		ldr	r1, =0x16
		str	r1, [r0]
		ldr	r1, =0x88
		str	r1, [r0]

		/* init POR */
		ldr	r2, =0x50000024	
		ldr	r1, =0x00005aa5
		str	r1, [r2]

		/* lock register */
		movs	r1, #0
		str	r1, [r0]

		ldr	r0, =SystemInit
		blx	r0
		ldr	r0, =__main
		bx	r0
		.endfunc

	.func	NMI_Handler
		.weak	NMI_Handler
		b	.
		.endfunc

	.func	HardFault_Handler
		.weak 	HardFault_Handler
		.if	semihosted
			ldr	r0, [r13, #24]
			ldrh	r1, [r0]
			ldr	r2, =0xBEAB
			cmp	r1, r2
			bne	HardFault_Handler_Ret

			add	r0, #4
			str	r0, [r13, #24]

			bx	lr
HardFault_Handler_Ret:
		.endif
		b	.
	.endfunc

	.func	SVC_Handler
		.weak 	SVC_Handler
		b	.
	.endfunc

	.func	PendSV_Handler
		.weak	PendSV_Handler
		b	.
	.endfunc

	.func	SysTick_Handler
		.weak	SysTick_Handler
		b	.
	.endfunc

	.func	Default_Handler
		.weak	BOD_IRQHandler  
		.weak	WDT_IRQHandler  
		.weak	EINT0_IRQHandler
		.weak	EINT1_IRQHandler
		.weak	GPAB_IRQHandler 
		.weak	GPCDE_IRQHandler
		.weak	PWMA_IRQHandler 
		.weak	PWMB_IRQHandler 
		.weak	TMR0_IRQHandler 
		.weak	TMR1_IRQHandler 
		.weak	TMR2_IRQHandler 
		.weak	TMR3_IRQHandler 
		.weak	UART02_IRQHandler
		.weak	UART1_IRQHandler
		.weak	SPI0_IRQHandler 
		.weak	SPI1_IRQHandler 
		.weak	SPI2_IRQHandler 
		.weak	SPI3_IRQHandler 
		.weak	I2C0_IRQHandler 
		.weak	I2C1_IRQHandler 
		.weak	CAN0_IRQHandler 
		.weak	Default_Handler
		.weak	Default_Handler 
		.weak	USBD_IRQHandler  
		.weak	PS2_IRQHandler  
		.weak	ACMP_IRQHandler 
		.weak	PDMA_IRQHandler
		.weak	I2S_IRQHandler 
		.weak	PWRWU_IRQHandler
		.weak	ADC_IRQHandler
		.weak	Default_Handler  
		.weak	RTC_IRQHandler  
		b	.
		.endfunc 

	.if semihosted
		.align
	.func	SH_DoCommand
		bkpt	0xab
		b	SH_ICE
	SH_HardFault:
		movs	r0, #0
		bx	lr
	SH_ICE:
		cmp	r2, #0
		beq	SH_END
		str	r0, [r2]
	SH_END
		movs	r0, #1
		bx	lr
		.align
	.endfunc
	.endif

