    <b>Clone OpenEmbedded repository:</b><br>
    <code>git clone https://github.com/openembedded/meta-openembedded.git</code>

    <b>Navigate to the cloned repository and initialize the build environment:</b><br>
    <code>cd meta-openembedded<br>
    source oe-init-build-env build-raspi4</code>

    <b>Add the meta-python layer to your build environment:</b><br>
    <code>bitbake-layers add-layers ../meta-openembedded/meta-python</code>

Step 2: Create Custom Machine and Distro Layers (meta-embabi)

    <b>Create the meta-embabi layer:</b><br>
    <code>cd ..<br>
    bitbake-layers create-layer meta-embabi<br>
    cd meta-embabi</code>

    <b>Machine Configuration:</b><br>
        <b>Create machine configuration file:</b><br>
        <code>mkdir -p conf/machine<br>
        touch conf/machine/embabi-machine.conf</code>
        <b>Add configuration to <code>embabi-machine.conf</code>:</b><br>
        <pre>require conf/machine/raspberrypi4.conf<br>
        MACHINEOVERRIDES .= ":raspberrypi4:embabi-machine"<br>
        ENABLE_W1 = "1"<br>
        ENABLE_UART = "1"<br>
        ENABLE_I2C = "1"<br>
        MACHINE_FEATURES += " wifi"</pre>

    <b>Distro Configuration:</b><br>
        <b>Create distro configuration file:</b><br>
        <code>mkdir -p conf/distro<br>
        touch conf/distro/mydistro.conf</code>
        <b>Add configuration to <code>mydistro.conf</code>:</b><br>
        <pre>require conf/distro/poky.conf<br>
        DISTRO = "mydistro"<br>
        DISTRO_NAME = "embabi distro"<br>
        DISTRO_VERSION = "1.0"<br>
        hostname_pn-base-files = "embabi_1"<br>
        DISTRO_FEATURES_remove = " pcmcia pci 3g"<br>
        INIT_MANAGER = "systemd"<br>
        PARALLEL_MAKE = "-j 6"<br>
        BB_NUMBER_PARSE_THREADS = "6"</pre>

Step 3: Add Recipe for GUI Application (guiled)

    <b>Create Recipe:</b><br>
    <code>mkdir -p recipes-gui/hello<br>
    touch recipes-gui/hello/guiled.bb</code>
        <b>Add content to <code>guiled.bb</code>:</b><br>
        <pre>SUMMARY = "Python Script"<br>
        LICENSE = "CLOSED"<br>
        SRC_URI = "file://gui.py"<br>
        <br>
        S = "${WORKDIR}"<br>
        <br>
        do_install() {<br>
            install -d ${D}/usr/bin<br>
            install -m 0755 ${S}/gui.py ${D}/usr/bin/gui.py<br>
        }<br>
        <br>
        FILES_${PN} += "/usr/bin/gui.py"</pre>

    <b>Create GUI Python Script:</b><br>
    <code>mkdir -p recipes-gui/hello/files<br>
    touch recipes-gui/hello/files/gui.py</code>

Step 4: Customize Image (embabi-sato)

    <b>Create Image Recipe:</b><br>
    <code>mkdir -p recipes-core/images<br>
    touch recipes-core/images/embabi-sato.bb</code>

    <b>Add content to <code>embabi-sato.bb</code>:</b><br>
    <pre>include recipes-sato/images/core-image-sato.bb<br>
    <br>
    IMAGE_INSTALL += " python3 python3-pip tcl tk python3-numpy python3-kivy strace cmake guiled"<br>
    IMAGE_FEATURES += " ssh-server-dropbear tools-sdk x11"<br>
    IMAGE_INSTALL += " net-tools iproute2"</pre>

Step 5: Build Your Custom Image

    <b>Configure Build:</b><br>
    <code>cd ../build-raspi4</code>

    <b>Set your distro and machine in <code>conf/local.conf</code>:</b><br>
    <pre>DISTRO ?= "mydistro"<br>
    MACHINE ?= "embabi-machine"</pre>

    <b>Start the build:</b><br>
    <code>bitbake embabi-sato</code>
