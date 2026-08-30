# Orlan

[![CI](https://github.com/Sam-DarkBall-Mods/Orlan/actions/workflows/ci.yml/badge.svg)](https://github.com/Sam-DarkBall-Mods/Orlan/actions/workflows/ci.yml)

Orlan adds UAVs and tripod launchers for all three sides, along with a reload
box and a custom operator display. The optional `orlan_fire_support` PBO adds
the communication menu and scripts used to call and guide artillery fire.

## Requirements

- Arma 3 2.22 or newer

## Building

```bash
python3 -B -m unittest discover -s tests -p "test_*.py" -v
hemtt check
hemtt build --no-bin
```

The main release keeps `orlan.pbo`. Fire support is packaged separately under
`optionals/@orlan_fire_support`. The old repository state is available from
the `legacy-2023` tag.

## License

Code and configs use GPL-2.0-or-later. Original models, textures, materials and
audio use APL-SA. See [LICENSES.md](LICENSES.md).
