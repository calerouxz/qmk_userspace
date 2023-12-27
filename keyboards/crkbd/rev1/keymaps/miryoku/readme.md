# Flashing miryoku for Corne/Crkbd

## QWERTY, Windows
Compile
```
qmk compile -kb crkbd -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN \
```
Flash
```
qmk flash -kb crkbd -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN \
```
