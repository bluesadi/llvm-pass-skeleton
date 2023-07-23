#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
using namespace llvm;

namespace {

struct SkeletonPass : public PassInfoMixin<SkeletonPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &FAM) {
        errs() << "I saw a function called " << F.getName() << "!\n";
        return PreservedAnalyses::all();
    }

    // It should return true, otherwise this pass will not work when no optimization flag (i.e.,
    // -O0) is set.
    // See: https://llvm.org/docs/WritingAnLLVMNewPMPass.html#required-passes
    static bool isRequired() { return true; }
};

} // namespace

extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK llvmGetPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "SkeletonPass", "v0.1", [](PassBuilder &PB) {
                PB.registerPipelineParsingCallback(
                    [](StringRef PassName, FunctionPassManager &FPM, ...) {
                        if (PassName == "skeleton-pass") {
                            FPM.addPass(SkeletonPass());
                            return true;
                        }
                        return false;
                    });
            }};
}