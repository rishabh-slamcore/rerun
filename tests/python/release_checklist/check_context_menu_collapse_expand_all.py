from __future__ import annotations

import os
from argparse import Namespace
from uuid import uuid4

import rerun as rr

README = """
# Context Menu - Add entity to new space view

## Blueprint tree

* Reset the blueprint.
* Right-click on Viewport and select "Collapse all". Check everything is collapsed by manually expending everything.
* Right-click on Viewport and select "Collapse all" and then "Expend all". Check everything is expanded.

## Streams tree

* Same as above, with the `world/` entity.


## Multi-selection

* Same as above, with both the viewport (blueprint tree) and `world/` (streams tree) selected.
"""


def log_readme() -> None:
    rr.log("readme", rr.TextDocument(README, media_type=rr.MediaType.MARKDOWN), timeless=True)


def log_some_space_views() -> None:
    # TODO(ab): add a deep-ish container hierarchy blueprint for more collapse/expand fun

    rr.set_time_sequence("frame_nr", 0)

    rr.log("/", rr.Boxes3D(centers=[0, 0, 0], half_sizes=[1, 1, 1]))
    rr.log("/world/robot/arm/actuator/thing", rr.Boxes3D(centers=[0.5, 0, 0], half_sizes=[0.1, 0.1, 0.1]))


def run(args: Namespace) -> None:
    # TODO(cmc): I have no idea why this works without specifying a `recording_id`, but
    # I'm not gonna rely on it anyway.
    rr.script_setup(args, f"{os.path.basename(__file__)}", recording_id=uuid4())

    log_readme()
    log_some_space_views()


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="Interactive release checklist")
    rr.script_add_args(parser)
    args = parser.parse_args()
    run(args)
