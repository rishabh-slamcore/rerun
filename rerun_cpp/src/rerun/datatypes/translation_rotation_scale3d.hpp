// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/translation_rotation_scale3d.fbs".

#pragma once

#include "../result.hpp"
#include "rotation3d.hpp"
#include "scale3d.hpp"
#include "vec3d.hpp"

#include <cstdint>
#include <memory>
#include <optional>

namespace arrow {
    class DataType;
    class MemoryPool;
    class StructBuilder;
} // namespace arrow

namespace rerun {
    namespace datatypes {
        /// **Datatype**: Representation of an affine transform via separate translation, rotation & scale.
        struct TranslationRotationScale3D {
            /// 3D translation vector, applied last.
            std::optional<rerun::datatypes::Vec3D> translation;

            /// 3D rotation, applied second.
            std::optional<rerun::datatypes::Rotation3D> rotation;

            /// 3D scale, applied first.
            std::optional<rerun::datatypes::Scale3D> scale;

            /// If true, this transform is from the parent space to the space where the transform was logged.
            ///
            /// If false (default), the transform maps from this space to its parent,
            /// i.e. the translation is the position in the parent space.
            bool from_parent;

          public:
            // Extensions to generated type defined in 'translation_rotation_scale3d_ext.cpp'

            static const TranslationRotationScale3D IDENTITY;

            /// Creates a new 3D transform from translation/rotation/scale.
            ///
            /// @param _from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            TranslationRotationScale3D(
                const std::optional<Vec3D>& _translation,
                const std::optional<Rotation3D>& _rotation, const std::optional<Scale3D>& _scale,
                bool _from_parent = false
            )
                : translation(_translation),
                  rotation(_rotation),
                  scale(_scale),
                  from_parent(_from_parent) {}

            /// Creates a new 3D transform from translation/rotation/uniform-scale.
            ///
            /// @param _from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            ///
            /// Implementation note: This explicit overload prevents interpretation of the float as
            /// bool, leading to a call to the wrong overload.
            TranslationRotationScale3D(
                const Vec3D& _translation, const Rotation3D& _rotation, float uniform_scale,
                bool _from_parent = false
            )
                : translation(_translation),
                  rotation(_rotation),
                  scale(uniform_scale),
                  from_parent(_from_parent) {}

            /// Creates a new rigid transform (translation & rotation only).
            ///
            /// @param _from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            TranslationRotationScale3D(
                const Vec3D& _translation, const Rotation3D& _rotation, bool _from_parent = false
            )
                : translation(_translation),
                  rotation(_rotation),
                  scale(std::nullopt),
                  from_parent(_from_parent) {}

            /// From translation & scale only.
            ///
            /// @param _from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            TranslationRotationScale3D(
                const Vec3D& _translation, const Scale3D& _scale, bool _from_parent = false
            )
                : translation(_translation),
                  rotation(std::nullopt),
                  scale(_scale),
                  from_parent(_from_parent) {}

            /// From translation & uniform scale only.
            ///
            /// @param _from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            ///
            /// Implementation note: This explicit overload prevents interpretation of the float as
            /// bool, leading to a call to the wrong overload.
            TranslationRotationScale3D(
                const Vec3D& _translation, float uniform_scale, bool _from_parent = false
            )
                : translation(_translation),
                  rotation(std::nullopt),
                  scale(uniform_scale),
                  from_parent(_from_parent) {}

            /// From rotation & scale only.
            ///
            /// @param _from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            TranslationRotationScale3D(
                const Rotation3D& _rotation, const Scale3D& _scale, bool _from_parent = false
            )
                : translation(std::nullopt),
                  rotation(_rotation),
                  scale(_scale),
                  from_parent(_from_parent) {}

            /// From rotation & uniform scale only.
            ///
            /// @param _from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            ///
            /// Implementation note: This explicit overload prevents interpretation of the float as
            /// bool, leading to a call to the wrong overload.
            TranslationRotationScale3D(
                const Rotation3D& _rotation, float uniform_scale, bool _from_parent = false
            )
                : translation(std::nullopt),
                  rotation(_rotation),
                  scale(uniform_scale),
                  from_parent(_from_parent) {}

            /// From translation only.
            ///
            /// @param from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            TranslationRotationScale3D(const Vec3D& _translation, bool _from_parent = false)
                : translation(_translation),
                  rotation(std::nullopt),
                  scale(std::nullopt),
                  from_parent(_from_parent) {}

            /// From rotation only.
            ///
            /// @param from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            TranslationRotationScale3D(const Rotation3D& _rotation, bool _from_parent = false)
                : translation(std::nullopt),
                  rotation(_rotation),
                  scale(std::nullopt),
                  from_parent(_from_parent) {}

            /// From scale only.
            ///
            /// @param from_parent If true, the transform maps from the parent space to the space
            /// where the transform was logged. Otherwise, the transform maps from the space to its
            /// parent.
            TranslationRotationScale3D(const Scale3D& _scale, bool _from_parent = false)
                : translation(std::nullopt),
                  rotation(std::nullopt),
                  scale(_scale),
                  from_parent(_from_parent) {}

          public:
            TranslationRotationScale3D() = default;

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static Result<std::shared_ptr<arrow::StructBuilder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static Error fill_arrow_array_builder(
                arrow::StructBuilder* builder, const TranslationRotationScale3D* elements,
                size_t num_elements
            );
        };
    } // namespace datatypes
} // namespace rerun
