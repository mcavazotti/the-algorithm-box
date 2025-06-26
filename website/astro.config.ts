import { defineConfig } from "astro/config";
import starlight from "@astrojs/starlight";
import mdx from "@astrojs/mdx";
import react from "@astrojs/react";
import githubData from "./src/config/github-data";
import remarkMath from "remark-math";
import rehypeKatex from "rehype-katex";

// https://astro.build/config
export default defineConfig({
  markdown: {
    rehypePlugins: [rehypeKatex],
    remarkPlugins: [remarkMath],
  },
  integrations: [
    react(),
    starlight({
      title: "The Algorithm Box",
      logo: {
        src: "./src/assets/Logo.png",
      },
      customCss: ["./src/styles/custom.css"],
      social: [{ icon: "github", label: "GitHub", href: githubData.repositoryAddress() }],
      favicon: "favicon.ico",
      credits: true,
      head: [
        {
          tag: "link",
          attrs: {
            href: "https://cdn.jsdelivr.net/npm/katex@0.16.22/dist/katex.min.css",
            rel: "stylesheet",
          },
        },
      ],
      sidebar: [
        {
          label: "Code",
          autogenerate: { directory: "code" },
        },
      ],
    }),
    mdx(),
  ],
});
