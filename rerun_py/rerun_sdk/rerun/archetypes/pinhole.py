# DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/python.rs
# Based on "crates/re_types/definitions/rerun/archetypes/pinhole.fbs".

# You can extend this class by creating a "PinholeExt" class in "pinhole_ext.py".

from __future__ import annotations

from attrs import define, field

from .. import components
from .._baseclasses import (
    Archetype,
)
from .pinhole_ext import PinholeExt

__all__ = ["Pinhole"]


@define(str=False, repr=False, init=False)
class Pinhole(PinholeExt, Archetype):
    """
    Camera perspective projection (a.k.a. intrinsics).

    Example
    -------
    ```python
    import numpy as np
    import rerun as rr
    import rerun.experimental as rr2

    rr.init("rerun_example_pinhole", spawn=True)
    rng = np.random.default_rng(12345)

    image = rng.uniform(0, 255, size=[3, 3, 3])
    rr2.log("world/image", rr2.Pinhole(focal_length=3, width=3, height=3))
    rr2.log("world/image", rr2.Image(image))
    ```
    """

    # __init__ can be found in pinhole_ext.py

    image_from_camera: components.PinholeProjectionArray = field(
        metadata={"component": "required"},
        converter=components.PinholeProjectionArray.from_similar,  # type: ignore[misc]
    )
    """
    Camera projection, from image coordinates to view coordinates.
    """

    resolution: components.ResolutionArray | None = field(
        metadata={"component": "optional"},
        default=None,
        converter=components.ResolutionArray.optional_from_similar,  # type: ignore[misc]
    )
    """
    Pixel resolution (usually integers) of child image space. Width and height.

    Example:
    ```text
    [1920.0, 1440.0]
    ```

    `image_from_camera` project onto the space spanned by `(0,0)` and `resolution - 1`.
    """

    __str__ = Archetype.__str__
    __repr__ = Archetype.__repr__