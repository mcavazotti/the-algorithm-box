import type { StarlightExpressiveCodeOptions } from "@astrojs/starlight/expressive-code";
import { pluginLineNumbers } from "@expressive-code/plugin-line-numbers";

export default {
  plugins: [pluginLineNumbers()],
  defaultProps: {
    showLineNumbers: true,
    overridesByLang: {
      'c++,cpp': {
        showLineNumbers: true,
      },}
  },
  frames: {
    showCopyToClipboardButton: false,
  },
} satisfies StarlightExpressiveCodeOptions;
