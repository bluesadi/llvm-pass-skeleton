add_llvm_library(SkeletonPass MODULE
    # List your source files here.
    Skeleton.cpp

    PLUGIN_TOOL
    opt
)