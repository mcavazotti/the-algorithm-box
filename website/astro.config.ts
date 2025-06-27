import { defineConfig } from "astro/config";
import starlight from "@astrojs/starlight";
import mdx from "@astrojs/mdx";
import react from "@astrojs/react";
import githubData from "./src/config/github-data";
import remarkMath from "remark-math";
import rehypeKatex from "rehype-katex";
import starlightUtils from "@lorenzo_lewis/starlight-utils";
import starlightAutoSidebar from "starlight-auto-sidebar";

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
      favicon: "favicon.ico",
      logo: {
        src: "./src/assets/Logo.png",
      },
      customCss: ["./src/styles/custom.scss"],
      social: [{ icon: "github", label: "GitHub", href: githubData.repositoryAddress() }],
      credits: true,
      lastUpdated: true,
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
      components: {
        Hero: "@components/overrides/Hero.astro",
      },
      plugins: [
        starlightAutoSidebar(),
      ],
    }),
    mdx(),
  ],
});
