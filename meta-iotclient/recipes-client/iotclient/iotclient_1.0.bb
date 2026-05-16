SUMMARY = "IoT Client Terminal Application"
DESCRIPTION = "A C++ terminal client application for simulating IoT temperature readings"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://src \
           file://include \
           file://Makefile"

S = "${WORKDIR}"

do_compile() {
    oe_runmake
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 client_app.exe ${D}${bindir}/client_app.exe
}
