#include "memfs.h"
#include "memfs-interface.h"

using namespace Memfs;

FSP_FILE_SYSTEM* MemFs::GetRawFileSystem() const {
	return this->fileSystem;
}

std::wstring& MemFs::GetVolumeLabel() {
	return this->volumeLabel;
}

void MemFs::SetVolumeLabel(const std::wstring& str) {
	std::wstring label = str;
	if (label.length() >= Interface::MAX_VOLUME_LABEL_STR_LENGTH) {
		label = label.substr(0, Interface::MAX_VOLUME_LABEL_STR_LENGTH - 1);
	}

	this->volumeLabel = label;
}