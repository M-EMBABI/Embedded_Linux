<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Setup Custom Embedded Linux Distribution (embabi) with GUI using Kivy on Raspberry Pi 4</title>
<style>
    body {
        font-family: Arial, sans-serif;
        line-height: 1.6;
    }
    .step {
        margin-bottom: 20px;
    }
    .code {
        display: block;
        background-color: #f0f0f0;
        padding: 10px;
        margin-top: 10px;
    }
    .pre {
        background-color: #f0f0f0;
        padding: 10px;
        white-space: pre-wrap;
    }
</style>
</head>
<body>

<h1>Step-by-Step Guide to Setup Custom Embedded Linux Distribution (embabi) with GUI using Kivy on Raspberry Pi 4</h1>

<div class="step">
    <h2>Step 1: Clone OpenEmbedded and Initialize Build Environment</h2>

    <p><b>Clone OpenEmbedded repository:</b><br>
    <code class="code">git clone https://github.com/openembedded/meta-openembedded.git</code></p>

    <p><b>Navigate to the cloned repository and initialize the build environment:</b><br>
    <code class="code">cd meta-openembedded<br>
    source oe-init-build-env build-raspi4</code></p>

    <p><b>Add the meta-python layer to your build environment:</b><br>
    <code class="code">bitbake-layers add-layers ../meta-openembedded/meta-python</code></p>
</div>

<div class="step">
    <h2>Step 2: Create Custom Machine and Distro Layers (meta-embabi)</h2>

    <p><b>Create the meta-embabi layer:</b><br>
    <code class="code">cd ..<br>
    bitbake-layers create-layer meta-embabi<br>
    cd meta-embabi</code></p>

    <p><b>Machine Configuration:</b></p>
    <ul>
        <li><b>Create machine configuration file:</b><br>
        <code class="code">mkdir -p conf/machine<br>
        touch conf/machine/embabi-machine.conf</code></li>
        <li><b>Add configuration to <code>embabi-machine.conf</code>:</b><br>
        <pre class="pre">require conf/machine/raspberrypi4.conf<br>
        MACHINEOVERRIDES .= ":raspberrypi4:embabi-machine"<br>
        ENABLE_W1 = "1"<br>
        ENABLE_UART = "1"<br>
        ENABLE_I2C = "1"<br>
        MACHINE_FEATURES += " wifi"</pre></li>
    </ul>

    <p><b>Distro Configuration:</b></p>
    <ul>
        <li><b>Create distro configuration file:</b><br>
        <code class="code">mkdir -p conf/distro<br>
        touch conf/distro/mydistro.conf</code></li>
        <li><b>Add configuration to <code>mydistro.conf</code>:</b><br>
        <pre class="pre">require conf/distro/poky.conf<br>
        DISTRO = "mydistro"<br>
        DISTRO_NAME = "embabi distro"<br>
        DISTRO_VERSION = "1.0"<br>
        hostname_pn-base-files = "embabi_1"<br>
        DISTRO_FEATURES_remove = " pcmcia pci 3g"<br>
        INIT_MANAGER = "systemd"<br>
        PARALLEL_MAKE = "-j 6"<br>
        BB_NUMBER_PARSE_THREADS = "6"</pre></li>
    </ul>
</div>

<div class="step">
    <h2>Step 3: Add Recipe for GUI Application (guiled)</h2>

    <p><b>Create Recipe:</b><br>
    <code class="code">mkdir -p recipes-gui/hello<br>
    touch recipes-gui/hello/guiled.bb</code></p>

    <p><b>Add content to <code>guiled.bb</code>:</b><br>
    <pre class="pre">SUMMARY = "Python Script"<br>
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
    FILES_${PN} += "/usr/bin/gui.py"</pre></p>

    <p><b>Create GUI Python Script:</b><br>
    <code class="code">mkdir -p recipes-gui/hello/files<br>
    touch recipes-gui/hello/files/gui.py</code></p>
</div>

<div class="step">
    <h2>Step 4: Customize Image (embabi-sato)</h2>

    <p><b>Create Image Recipe:</b><br>
    <code class="code">mkdir -p recipes-core/images<br>
    touch recipes-core/images/embabi-sato.bb</code></p>

    <p><b>Add content to <code>embabi-sato.bb</code>:</b><br>
    <pre class="pre">include recipes-sato/images/core-image-sato.bb<br>
    <br>
    IMAGE_INSTALL += " python3 python3-pip tcl tk python3-numpy python3-kivy strace cmake guiled"<br>
    IMAGE_FEATURES += " ssh-server-dropbear tools-sdk x11"<br>
    IMAGE_INSTALL += " net-tools iproute2"</pre></p>
</div>

<div class="step">
    <h2>Step 5: Build Your Custom Image</h2>

    <p><b>Configure Build:</b><br>
    <code class="code">cd ../build-raspi4</code></p>

    <p><b>Set your distro and machine in <code>conf/local.conf</code>:</b><br>
    <pre class="pre">DISTRO ?= "mydistro"<br>
    MACHINE ?= "embabi-machine"</pre></p>

    <p><b>Start the build:</b><br>
    <code class="code">bitbake embabi-sato</code></p>
</div>

</body>
</html>
