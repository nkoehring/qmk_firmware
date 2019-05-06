SRC += koehr.c
ifeq ($(strip $(CALCULATOR_ENABLE)), yes)
  SRC += calculator.c
endif
