# Flashing miryoku for Cantor (remix / base)

## QWERTY, Windows
Compile
```
qmk compile -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN \
```
Flash
```
qmk flash -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN \
```
