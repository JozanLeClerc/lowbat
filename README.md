# lowbat

Very small script that runs in the background and warns you when your battery is low until you plug your laptop in.
It also is POSIX-compliant, which is nice.

## Dependencies

+ `make`
+ `libnotify`
+ `espeak`

## Installation

Open a terminal and run these commands:

```shell
git clone https://github.com/JozanLeClerc/lowbat.git
cd lowbat
sudo make install
```

Next you must find a way to get the script running when loging in. Add this to your startup programs manager/rc file of choice:

```shell
lowbat > /dev/null 2>&1 &
```

## Options

Two options are available:

+ `--say [MESSAGE]`
+ `--silent`

### Definitions

`--say "message"` will allow you to set your own warning message lowbat is active.

#### Example:

```shell
lowbat --say "your custom message" > /dev/null 2>&1
```

`--silent` disables audio warnings.

#### Example:

```shell
lowbat --silent > /dev/null 2>&1
```

## Uninstallation

```shell
sudo make uninstall
```

## See also

For more informations, see:

```shell
man 1 lowbat
```