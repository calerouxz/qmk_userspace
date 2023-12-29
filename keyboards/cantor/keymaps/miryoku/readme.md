# Flashing miryoku for Cantor (remix / base)

## QWERTY, Windows
Compile
```
qmk compile -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN
```
Flash
```
qmk flash -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=WIN
```

## QWERTY, Mac
Compile
```
qmk compile -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=MAC
```
Flash
```
qmk flash -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=QWERTY \
  -e MIRYOKU_EXTRA=COLEMAKDH \
  -e MIRYOKU_TAP=QWERTY \
  -e MIRYOKU_CLIPBOARD=MAC
```

## COLEMAKDH, Windows
Compile
```
qmk compile -c -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=COLEMAKDH \
  -e MIRYOKU_EXTRA=QWERTY \
  -e MIRYOKU_TAP=COLEMAKDH \
  -e MIRYOKU_CLIPBOARD=WIN
```
Flash
```
qmk flash -kb cantor -km miryoku  \
  -e MIRYOKU_ALPHAS=COLEMAKDH \
  -e MIRYOKU_EXTRA=QWERTY \
  -e MIRYOKU_TAP=COLEMAKDH \
  -e MIRYOKU_CLIPBOARD=WIN
```
