#
# ledrgbmatrix
# basic building rules
#

LEDRGBMATRIX_VERSION = origin/master
LEDRGBMATRIX_SITE_METHOD=git
LEDRGBMATRIX_SITE = git://github.com/lesk8heure/ledrgbmatrix

LEDRGBMATRIX_INSTALL_STAGING = YES

define LEDRGBMATRIX_BUILD_CMDS
    $(MAKE) CC=$(TARGET_CC) CXX=$(TARGET_CXX) AR=$(TARGET_AR) LD="$(TARGET_LD)" -C $(@D) all
endef

define LEDRGBMATRIX_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/autorun/demo $(TARGET_DIR)/usr/bin
    $(INSTALL) -D -m 0755 $(@D)/lib/librgbmatrix.so.1 $(TARGET_DIR)/usr/lib
endef

$(eval $(generic-package))
