TARGET=test_fuzzy
LOCALE=zh_CN
PO_DIR=$(shell pwd)/po
CFLAGS=-Wall -Werror -g -DPACKAGE=\"$(TARGET)\" -DLOCALEDIR=\"$(PO_DIR)\"
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(TARGET).pot $(LOCALE).po $(TARGET).mo $(TARGET)

$(TARGET).pot: $(TARGET).c
		xgettext -o $(TARGET).pot --add-comments=- -k_ $(TARGET).c;

$(LOCALE).po: $(TARGET).pot
	if [ -f $(LOCALE).po ] ; then                               \
	    msgmerge $(LOCALE).po $(TARGET).pot > new.po;           \
	else                                                        \
		msginit --locale=$(LOCALE) --input=$^ --no-translator ; \
	fi

$(TARGET).mo: new.po
	mkdir -p $(PO_DIR)/$(LOCALE)/LC_MESSAGES
	msgfmt -f new.po -o $(PO_DIR)/$(LOCALE)/LC_MESSAGES/$@


%.o: %.c
	  $(CC) -o $(patsubst %.o, %, $@) $^

clean:
	rm -f *.o *~ $(TARGET) *.po *.pot *.mo
	@echo To remove po directory, use: rm -rf $(PO_DIR)
