# Flashing miryoku for Corne/Crkbd

## QWERTY, Windows
Compile
```
qmk compile -c -kb crkbd -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN
```
Flash
```
qmk flash -kb crkbd -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN
```

## COLEMAK-DH, Windows
Compile
```
qmk compile -c -kb crkbd -km miryoku  \
  -e MIRYOKU_ALPHAS=COLEMAKDH \
  -e MIRYOKU_EXTRA=QWERTY \
  -e MIRYOKU_TAP=COLEMAKDH \
  -e MIRYOKU_CLIPBOARD=WIN
```
Flash
```
qmk flash -kb crkbd -km miryoku  \
  -e MIRYOKU_ALPHAS=COLEMAKDH \
  -e MIRYOKU_EXTRA=QWERTY \
  -e MIRYOKU_TAP=COLEMAKDH \
  -e MIRYOKU_CLIPBOARD=WIN
```
