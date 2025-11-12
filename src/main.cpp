#include "huggingface_hub.h"
#include <iostream>

int main()
{
#ifdef _WIN32
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
  SetConsoleMode(hOut, dwMode);
#endif

  std::string repo_id = "rhasspy/piper-voices";
  std::string filename = "en/en_US/lessac/low/en_US-lessac-low.onnx.json";

  if (huggingface_hub::hf_hub_download(repo_id, filename).success)
  {
    std::cout << "Downloaded " << filename << " from " << repo_id << std::endl;
  }
  else
  {
    std::cout << "Failed to download " << filename << " from " << repo_id << std::endl;
  }
}